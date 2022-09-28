#include "../include/common.h"

#define UINT32_MIN 0
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

/**
 * @brief checks if argument is a number
 * 
 * @param operand - argument given by user
 * @return int 0 if argument is not a number, 1 if it is a number
 */

int is_number(char operand[])
{
    int check = 0;
    int i = 0;
    if (operand[i] == '-')
    {
        i++;
    }
    for (i; i < strlen(operand); i++)
    {
        if (!isdigit(operand[i]))
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief determines if unsigned or signed operation
 * 
 * @param operator - the operator of the function
 * @return int - 1: signed, 0: unsigned, -1: error
 */

int signage_decider(uint16_t operator)
{
    int sign = 0;
    if (operator > 0 && operator < 6)
    {
        sign = 1;
    }
    else if (operator > 5 && operator < 13)
    {
        sign = 0;
    }
    else
    {
        sign = -1;
    }
    return sign;
}

/**
 * @brief returns index of respective operator. index understood by main
 * 
 * @param operand2 - the operator given by the user as an argument
 * @return int - index to respective operator
 */

int operand_decider(char *operand2)
{
    int decided = 0;
    if (!strcmp(operand2, "+"))
    {
        decided = 1;
    }
    else if (!strcmp(operand2, "-"))
    {
        decided = 2;
    }
    else if (!strcmp(operand2, "*"))
    {
        decided = 3;
    }
    else if (!strcmp(operand2, "/"))
    {
        decided = 4;
    }
    else if (!strcmp(operand2, "%"))
    {
        decided = 5;
    }
    else if (!strcmp(operand2, "<<"))
    {
        decided = 6;
    }
    else if (!strcmp(operand2, ">>"))
    {
        decided = 7;
    }
    else if (!strcmp(operand2, "&"))
    {
        decided = 8;
    }
    else if (!strcmp(operand2, "|"))
    {
        decided = 9;
    }
    else if (!strcmp(operand2, "^"))
    {
        decided = 10;
    }
    else if (!strcmp(operand2, "<<<"))
    {
        decided = 11;
    }
    else if (!strcmp(operand2, ">>>"))
    {
        decided = 12;
    }
    return decided;
}

/**
 * @brief checks if operand is within 32 bit signed range
 * 
 * @param operand - some long
 * @return int - returns 0 if it is outside of range, 1 if it is valid INT_32
 */

int signed_value_check32(long operand)
{
    int check = 0;
    if ((operand >= INT32_MIN) && (operand <= INT32_MAX))
    {
        check++;
    }
    return check;
}

/**
 * @brief checks if operand is within 64 bit signed range
 * 
 * @param operand - some long
 * @return int - returns 0 if it is outside of range, 1 if it is valid INT_32
 */

int signed_value_check64(long operand)
{
    int check = 0;
    if ((operand >= INT64_MIN) && (operand <= INT64_MAX))
    {
        check++;
    }
    return check;
}

/**
 * @brief checks if operand is within 32 bit unsigned range
 * 
 * @param operand - some long
 * @return int - returns 0 if it is outside of range, 1 if it is valid UINT32
 */

int unsigned_value_check32(long operand)
{
    int check = 0;
    if ((operand >= UINT32_MIN) && (operand <= UINT32_MAX))
    {
        check++;
    }
    return check;
}

/**
 * @brief checks if operand is within 32 bit unsigned range
 * 
 * @param operand - some long
 * @return int - returns 0 if it is outside of range, 1 if it is valid UINT32
 */

int unsigned_value_check64(long operand)
{
    int check = 0;
    if ((operand >= UINT64_MIN) && (operand <= UINT64_MAX))
    {
        check++;
    }
    return check;
}

/**
 * @brief signed integer operations
 * 
 * @param operand1 - first operand
 * @param operator - operator can be +,-,*,/
 * @param operand2 - second operand
 * @param write_result - int64_t * to store result
 * @return int - returns 1 if successful, 0 if error
 */
int signedcalc(int64_t operand1, uint8_t operator, int64_t operand2, int64_t * write_result)
{
    int64_t result;
    int pass = 0;
    if (signed_value_check64(operand1) && signed_value_check64(operand2))
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

        if (!signed_value_check64(result))
        {
            printf(
                "\nSolution was not within int64_t standards: %ld\n", result);
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

/**
 * @brief unsigned integer operations
 * 
 * @param operand1 - first operand
 * @param operator - operator can be <<,>>,&,|,^,<<<,>>>
 * @param operand2 - second operand
 * @param write_result - uint64_t * to store result
 * @return int - returns 1 if successful, 0 if error
 */
int unsignedcalc(uint64_t operand1, uint8_t operator, uint64_t operand2, int64_t * write_result)
{
    uint64_t result;
    int pass = 0;
    if (unsigned_value_check64(operand1) && unsigned_value_check64(operand1))
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