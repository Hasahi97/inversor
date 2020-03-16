/* Data de submissao:
 * Nome: Henrique Shinji Yamada Asahi
 * RA: 217832
 */

#include <stdio.h>
const int tam_buffer=100;

typedef struct {
  unsigned char dados[100];
  int length;
} stack, *Stack;

void stack_init(Stack sta)
{
    sta->length = 0;
}

void push(Stack sta, char c)
{
	if(sta->length < 100)
	{
		sta->dados[sta->length] = c;
		sta->length++;
	}
}

char pop(Stack sta)
{
	unsigned char c;
	if(sta->length > 0)
	{
		sta->length--;
		c = sta->dados[sta->length];
	}
	return c;
}

int main() 
{
    char buffer[tam_buffer];
	stack pilha;
	unsigned int kBuffer, k;
	stack_init(&pilha);
	
	kBuffer = 0;
	
    fgets(buffer, tam_buffer, stdin);
    
    while(buffer[kBuffer] != '\n')
    {
        kBuffer++;
    }
    
    for(k = 0; k <= kBuffer; k++)
    {
        if(buffer[k] == ' ' || k == kBuffer)
        {
            while(pilha.length > 0)
            {
                printf("%c", pop(&pilha));
            }
            if(buffer[k] == ' ')
            {
				printf(" ");
			}
        }
        else
        {
            push(&pilha, buffer[k]);
        }
    }
    printf("\n");
    return 0;
}
