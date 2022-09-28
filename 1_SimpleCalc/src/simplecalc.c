#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UINT32_MIN 0
#define UINT_BITS 32

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
 * @brief returns index of respective operator. index understood by main
 * 
 * @param operand2 - the operator given by the user as an argument
 * @return int - index to respective operator
 */

int operand_decider(const char *operand2)
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

int signed_value_check(long operand)
{
    int check = 0;
    if ((operand >= INT32_MIN) && (operand <= INT32_MAX))
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

int unsigned_value_check(long operand)
{
    int check = 0;
    if ((operand >= UINT32_MIN) && (operand <= UINT32_MAX))
    {
        check++;
    }
    return check;
}

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        printf("There were 3 arguments supplied: \n%s %s %s = ", argv[1],
               argv[2], argv[3]);

        if (is_number(argv[1]) && is_number(argv[3]))
        {
            long n1 = atol(argv[1]);
            long n2 = atol(argv[3]);

            if ((operand_decider(argv[2]) > 0) && (operand_decider(argv[2]) < 6))
            {

                if (signed_value_check(n1) && signed_value_check(n2))
                {
                    //decides on operator and conducts math
                    switch (operand_decider(argv[2]))
                    {
                    case 1:
                        n1 = n1 + n2;
                        break;
                    case 2:
                        n1 = n1 - n2;
                        break;
                    case 3:
                        n1 = n1 * n2;
                        break;
                    case 4:
                        if (n2 != 0)
                        {
                            n1 = n1 / n2;
                        }
                        else
                        {
                            printf("Cannot divide by 0.\n");
                            return 0;
                        }
                        break;
                    case 5:
                        if (n2 != 0)
                        {
                            n1 = n1 / n2;
                        }
                        else
                        {
                            printf("Cannot divide by 0.\n");
                            return 0;
                        }
                        break;
                    }

                    if (signed_value_check(n1))
                    {
                        printf("%" SCNd32 "!\n", (int32_t)n1); //NOTE: cast safe due to check
                    }

                    else
                    {
                        printf(
                            "\nSolution was not within int32_t standards.\n");
                    }

                }

                else
                {
                    printf(
                        "\nWARNING: operand did not meet int32_t criteria.\n");
                }

            }
            else if ((operand_decider(argv[2]) > 5) &&
                     (operand_decider(argv[2]) < 13))
            {

                if (unsigned_value_check(n1) && unsigned_value_check(n2))
                {

                    switch (operand_decider(argv[2]))
                    {
                    case 6:
                        printf("%" PRIu32 "!\n",
                               ((uint32_t)(n1) << (uint32_t)(n2))); //NOTE: casting safe due to value and type check above
                        break;
                    case 7:
                        printf("%" PRIu32 "!\n",
                               ((uint32_t)(n1) >> (uint32_t)(n2))); //NOTE: casting safe due to value and type check above
                        break;
                    case 8:
                        printf("%" PRIu32 "!\n",
                               ((uint32_t)(n1) & (uint32_t)(n2))); //NOTE: casting safe due to value and type check above
                        break;
                    case 9:
                        printf("%" PRIu32 "!\n",
                               ((uint32_t)(n1) | (uint32_t)(n2))); //NOTE: casting safe due to value and type check above
                        break;
                    case 10:
                        printf("%" PRIu32 "!\n",
                               ((uint32_t)(n1) ^ (uint32_t)(n2))); //NOTE: casting safe due to value and type check above
                        break;
                    case 11:
                        printf("%" PRIu32 "!\n",
                               ((uint32_t)n1 << (uint32_t)n2) | ((uint32_t)n1 >> 
                               (UINT_BITS - (uint32_t)n2))); //NOTE: casting safe due to value and type check above
                        break;
                    case 12:
                        printf("%" PRIu32 "!\n",
                               ((uint32_t)n1 >> (uint32_t)n2) | ((uint32_t)n1 << 
                               (UINT_BITS - (uint32_t)n2))); //NOTE: casting safe due to value and type check above
                        break;
                    }

                }

                else
                {
                    printf(
                        "\nWARNING: operand did not meet uint32_t criteria.\n");
                }

            }

            else
            {
                operator_print_error();
            }

        }

        else
        {
            printf("\nWARNING: operand was not a number.\n");
        }

    }

    else if (argc > 4)
    {
        printf("Too many arguments supplied.\n");
        printf("Could be an operator issue.\n");
        operator_print_error();
    }

    else
    {
        printf("3 arguments expected.\n");
        printf("Could be an operator issue.\n");
        operator_print_error();
    }

}
