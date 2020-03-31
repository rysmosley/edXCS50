// credit.c written by Rebecca Mosley
// March 30, 2020

#include <stdio.h>
#include <cs50.h>

long cc_type_check();
void calcLuhns(long n);

int main(void)
{
    // Initial check on whether the number is proper length
    // and belongs to a credit card company
    long ccnumber = cc_type_check();

    // Conducts a check sum of the credit card digits
    calcLuhns(ccnumber);
}

long cc_type_check()
{
    bool validInput = false;
    long cc_input = 0;

    while (validInput == false)
    {
        cc_input = get_long("Number: ");

        // Check for 13 digit Visa, begins with 4
        if ((cc_input >= 4000000000000) && (cc_input <= 4999999999999))
        {
            printf("VISA\n");
            validInput = true;
            return cc_input;
        }

        // Check for American Express 34
        else if ((cc_input >= 340000000000000) && (cc_input <= 3499999999999))
        {
            validInput = true;
            printf("AMEX\n");
            return cc_input;
        }

        // Check for American Express 37
        else if ((cc_input >= 370000000000000) && (cc_input <= 379999999999999))
        {
            validInput = true;
            printf("AMEX\n");
            return cc_input;
        }

        // Check for 16 digit Visa, begins with 4
        else if ((cc_input >= 4000000000000000) && (cc_input <= 4999999999999999))
        {
            validInput = true;
            printf("VISA\n");
            return cc_input;
        }

        // Check for 16 digit MasterCard, begins with 51, 52, 53, 54, or 55
        else if ((cc_input >= 5100000000000000) && (cc_input <= 5599999999999999))
        {
            validInput = true;
            printf("MASTERCARD\n");
            return cc_input;
        }

        // Notify user INVALID and exit program
        else if (validInput == false)
        {
            printf("INVALID\n");
            return 0;
        }
    }
    return cc_input;
}

void calcLuhns(long n)
{
    // Each dx represents the place from Right to Left of the digit
    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    int d4 = 0;
    int d5 = 0;
    int d6 = 0;
    int d7 = 0;
    int d8 = 0;
    int d9 = 0;
    int d10 = 0;
    int d11 = 0;
    int d12 = 0;
    int d13 = 0;
    int d14 = 0;
    int d15 = 0;
    int d16 = 0;

    // Even digits multiplied by 2
    int d2x2 = 0;
    int d4x2 = 0;
    int d6x2 = 0;
    int d8x2 = 0;
    int d10x2 = 0;
    int d12x2 = 0;
    int d14x2 = 0;
    int d16x2 = 0;

    // Initial sum of even digits after they have been multiplied
    // by 2
    int initialSum = 0;

    // Check the sum of the initialSum and the remaining odd digits
    int checkSum = 0;

    // Pull out individual digits by place
    d1 = n % 10;
    d2 = (n / 10) % 10;
    d3 = (n / 100) % 10;
    d4 = (n / 1000) % 10;
    d5 = (n / 10000) % 10;
    d6 = (n / 100000) % 10;
    d7 = (n / 1000000) % 10;
    d8 = (n / 10000000) % 10;
    d9 = (n / 100000000) % 10;
    d10 = (n / 1000000000) % 10;
    d11 = (n / 10000000000) % 10;
    d12 = (n / 100000000000) % 10;
    d13 = (n / 1000000000000) % 10;
    d14 = (n / 10000000000000) % 10;
    d15 = (n / 100000000000000) % 10;
    d16 = (n / 1000000000000000) % 10;

    // Evens digits multiplied by 2
    d2x2 = d2 * 2;
    d4x2 = d4 * 2;
    d6x2 = d6 * 2;
    d8x2 = d8 * 2;
    d10x2 = d10 * 2;
    d12x2 = d12 * 2;
    d14x2 = d14 * 2;
    d16x2 = d16 * 2;

    // Subtract 9 from the digit if it is greater than
    // or equal to 10
    if (d2x2 >= 10)
    {
        d2x2 -= 9;
    }

    if (d4x2 >= 10)
    {
        d4x2 -= 9;
    }

    if (d6x2 >= 10)
    {
        d6x2 -= 9;
    }

    if (d8x2 >= 10)
    {
        d8x2 -= 9;
    }

    if (d10x2 >= 10)
    {
        d10x2 -= 9;
    }

    if (d12x2 >= 10)
    {
        d12x2 -= 9;
    }

    if (d14x2 >= 10)
    {
        d14x2 -= 9;
    }

    if (d16x2 >= 10)
    {
        d16x2 -= 9;
    }

    // Sum of digits multiplied by 2 and, if higher than 9, subtracted by 9
    initialSum = d2x2 +  d4x2 + d6x2 + d8x2 + d10x2 + d12x2 + d14x2 + d16x2;
    // Check sum total before modulus operation
    checkSum = initialSum + d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15;

    // If checkSum modulus 10 equals 0, the card is valid
    if ((checkSum % 10) == 0)
    {
        //printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

