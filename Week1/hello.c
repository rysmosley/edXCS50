#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get the user's name and assign it to variable answer
    string answer = get_string("What is your name?\n");

    // Print answer
    printf("Hello %s, nice to meet you.\n", answer);
}
