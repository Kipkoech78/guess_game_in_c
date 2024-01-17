#include<stdio.h>
#include<string.h>
void reversestring(char string[])
{
    int lenght= strlen(string);
    int start= 0;
    int end = lenght-1;
    // swap from 1st character to the last one
    while(start < end)
    {
        int temp= string[start];
        string[start]= string[end];
        string[end]= temp;

        start++;
        end --;

    }

}
int main()
{
    char inputstring[100];
    printf("enter a string \n");
    fgets(inputstring, sizeof(inputstring), stdin);
    // call reversestring function
    reversestring(inputstring);
    // print output
    printf("the string is %s \n ", inputstring);

    return 0;
}