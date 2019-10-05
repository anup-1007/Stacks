#include "stack.h"
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int balancing_symbols(char c[10])
{

	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	
	for(int i=0;i<strlen(c);i++)
	{
		
		if(c[i] == '[' || c[i] == '(' || c[i] == '{')
		{
			stk = stack_push(stk,c[i],&res);
			continue;
		}
		else if(c[i] == ']' && stk->data[stk->top]=='[')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(c[i] == ')' && stk->data[stk->top]=='(')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(c[i] == '}' && stk->data[stk->top]=='{')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else
		{
			assert(stk->top==2 || stk->top == -1);
			return 0;//if first symbol is },)or] then it will come out of function.
		}

	}
	stk = stack_peek(stk,&res);
	assert(stk->top == -1);

	return 0;
}

int postfix(char p[20])
{
	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	for(int i=0;i<strlen(p);i++)
    {
        if(isdigit(p[i]))
        {
            stk=stack_push(stk,p[i],&res);
            
        }
        else
        {
            
            char a,b;
            int c=0;
            a = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            b = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            if(p[i]=='+')
            {
                
            c = a -'0' + b - '0';
           
            }
            else if(p[i]=='-')
            {
                c = (b-'0') - (a-'0');
            }
            else if(p[i]=='*')
            {
                c = (b-'0') * (a-'0');
            }
            else if(p[i]=='/')
            {
                c = (b-'0')/(a-'0');
            }
           
            char pf = c+'0';
            stk = stack_push(stk,pf,&res);


            
        }
    }


stk = stack_peek(stk,&res);
assert(res.data=='6');


}

int main()
{
	char c[10] = "}((]";
	char c1[20] = "[({})]";
	
    balancing_symbols(c);
	balancing_symbols(c1);

    
	char p[20]="423+1*+3-";
	postfix(p);
	return 0;

}
