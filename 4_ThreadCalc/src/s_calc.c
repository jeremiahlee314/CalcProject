#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UINT64_MIN 0
#define UINT_BITS 64

int operator_print_error()
{
    printf("\nWARNING: please choose from the following operands:\n");
    printf("Addition: +\nSubtraction: -\nMultiplication: "
           "\"*\"\nDivision: /"
           "\nModulo: %%\nShift Left: \"<<\"\nShift Right: "
           "\">>\"\nAND: &\nOR: |\nXOR: \"^\"\nRotate Left: "
           "\"<<<\"\nRotate Right: \">>>\"\n\n");
    return 0;
}

// Returns 1 if signed and 0 if unsigned, -1 if invalid

int operand_decider(uint16_t operator)
{
    int sign = 0;
    if (operator> 0 && operator<6)
    {
        sign = 1;
    }
    else if (operator> 5 && operator<13)
    {
        sign = 0;
    }
    else
    {
        sign = -1;
    }
    return sign;
}

// Checks if signed value is within accepted values.

int signed_value_check(long operand)
{
    int check = 0;
    if (operand >= INT64_MIN && operand <= INT64_MAX)
    {
        check++;
    }
    return check;
}

// Checks if unsigned value is within accepted values.

int unsigned_value_check(long operand)
{
    int check = 0;
    if (operand >= UINT64_MIN && operand <= UINT64_MAX)
    {
        check++;
    }
    return check;
}

int signedcalc(int64_t operand1, uint8_t operator, int64_t operand2, int64_t * write_result)
{
    int64_t result = 0;
    int pass = 0;
    if (signed_value_check(operand1) && signed_value_check(operand2))
    {

        switch (operator)
        {
        case 1:
            result = operand1 + operand2;
            break;
        case 2:
            result = operand1 - operand2;
            break;
        case 3:
            result = operand1 * operand2;
            break;
        case 4:
            if (operand2 == 0)
            {
                printf("\nCannot divide by zero!\n");
            }
            else
            {
                result = operand1 / operand2;
            }
            break;
        case 5:
            if (operand2 == 0)
            {
                printf("\nCannot divide by zero!\n");
            }
            else
            {
                result = operand1 % operand2;
            }
            break;
        default:
            printf("Operator was wrong.\n");
            break;
        }

        if (!signed_value_check(result))
        {
            printf(
                "\nSolution was not within int64_t standards.\n");
        }
        else
        {
            *write_result = result;
            pass = 1;
        }
    }
    else
    {
        printf("Operands not within int64_t standards.\n");
    }
    return pass;
}

int unsignedcalc(uint64_t operand1, uint8_t operator, uint64_t operand2, int64_t * write_result)
{
    uint64_t result = 0;
    int pass = 0;
    if (unsigned_value_check(operand1) && unsigned_value_check(operand1))
    {
        switch (operator)
        {
        case 6:
            result = operand1 << operand2;
            break;
        case 7:
            result = operand1 >> operand2;
            break;
        case 8:
            result = operand1 & operand2;
            break;
        case 9:
            result = operand1 | operand2;
            break;
        case 10:
            result = operand1 ^ operand2;
            break;
        case 11:
            result = (operand1 << operand2) | (operand1 >> (UINT_BITS - operand2));
            break;
        case 12:
            result = (operand1 >> operand2) | (operand1 << (UINT_BITS - operand2));
            break;
        }
        *write_result = result;
        pass = 1;
    }

    else
    {
        printf(
            "Operand did not meet uint64_t criteria.\n");
    }
    return pass;
}
