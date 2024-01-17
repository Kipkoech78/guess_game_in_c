#include<iostream>
#include<string.h>
using namespace std;
# define MAX_STRING 100
void reverse_string(char str[])
{
    int lenght= strlen(str);
    int start=0;
    int end = lenght-1;

    while(start<end)
    {
        int temp = str[start];
        str[start] = str[end];
        str[end]= temp;
        start++;
        end--;

    }

}
int main()
{
    char input_string[MAX_STRING];
    cout<<"enter string you need a reverse output"<<endl;
    fgets(input_string, sizeof(input_string),stdin);
    reverse_string(input_string);
    cout<<"output is:";
    cout<<input_string<<endl;
}