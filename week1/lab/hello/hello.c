#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Asking the name of the user and storing it
    string name = get_string("What's your name?\n");
    
    // Display in the terminal
    printf("hello, %s\n", name);
}