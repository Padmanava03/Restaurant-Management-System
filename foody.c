#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct customer
{
    char id[225];
    char name[225];
    char add[225];
    char phn[225];
    int total;
} c[100000];

int numcheck(char *s);
void functime();
void customer();
void printmenu();
int exorder();
void order();
void stateorder(int n);
void printbill();
void convert(int n);
void record();
void convert_file(int n);
char *dish1 = "HAKKA NOODLES";
char *dish2 = "EGG ROLL";
char *dish3 = "CHICKEN ROLL";
char *dish4 = "MOTTON ROLL";
char *dish5 = "VEG THALI";
char *dish6 = "CHILLI PANEER";
char *dish7 = "SAHI PANEER";
char *dish8 = "CHICKEN CHAP";
char *dish9 = "CHICKEN BIRIYANI";
char *dish10 = "MOTTON BIRIYANI";
char *single_digit[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char *double_digit[] = {"", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char *tens_multiple[] = {"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char *ten_power[] = {"Hundred", "Thousand", "Lakh"};
char r[1000];
int i, total, j, l, day, year, temp;
int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;
int td1, td2, td3, td4, td5, td6, td7, td8, td9, td10;
int p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
int r1 = 30, r2 = 40, r3 = 60, r4 = 80, r5 = 100, r6 = 90, r7 = 120, r8 = 150, r9 = 230, r10 = 250;

int main()
{
    int grand_total = 0;
    FILE *cp;
    cp = fopen("Record.txt", "a");
    char h, a;
    customer();
    while (h != 'n' && h != 'N')
    {
        printf("\nWant to add more customers...y/n...");
        scanf(" %c", &h);
        fflush(stdin);
        if (h != 'n' && h != 'N')
        {
            i++;
            customer();
        }
    }
    for (int j = 0; j <= i; j++)
        grand_total += c[j].total;
    if (grand_total != 0)
    {
        fprintf(cp, "\nTOTAL INCOME: %d", grand_total);
        fprintf(cp, "\nTOTAL INCOME IN WORDS: ");
        fclose(cp);
        convert_file(grand_total);
    }
    printf("Want to see the record (y/n)\n--> ");
    scanf(" %c", &a);
    fflush(stdin);
    if (a == 'Y' || a == 'y')
    {
        FILE *fp;
        fp = fopen("Record.txt", "r");
        char ch = getc(fp);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = getc(fp);
        }
        fclose(fp);
    }
    else
        printf("THANK YOU, HAVE A GREAT DAY :D\n");
    return 0;
}

int numcheck(char *s)
{
    while (*s != '\0')
    {
        if (*s < 48 || *s > 57)
            return 0;
        s++;
    }
    return 1;
}

void functime()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    day = tm.tm_mday;
    temp = tm.tm_mon + 1;
    year = tm.tm_year + 1900;
}

void customer()
{
    functime();
    sprintf(c[i].id, "%s%d%d%d%d", "FE", year, temp, day * 10, i + 1);
    printf("Enter Customer details:\n");
    printf("Enter full name: ");
    fgets(c[i].name, sizeof(c[i].name), stdin);
    strtok(c[i].name, "\n");
    fflush(stdin);
    while (1)
    {
        printf("Enter phone number: ");
        fgets(c[i].phn, sizeof(c[i].phn), stdin);
        strtok(c[i].phn, "\n");
        fflush(stdin);
        if (numcheck(c[i].phn) == 1 && strlen(c[i].phn) == 10)
            break;
    }
    printf("Enter full address: ");
    fgets(c[i].add, sizeof(c[i].add), stdin);
    strtok(c[i].add, "\n");
    fflush(stdin);
    printf("\n");
    order();
}

void printmenu()
{
    printf("                      FOODY EXPRESS                     \n");
    printf("+-----------------------------------+------------------+\n");
    printf("|ITEMS                              |     PRICE(INR)   |\n");
    printf("+-----------------------------------+------------------+\n");
    printf("|1.HAKKA NOODLES                    |        30        |\n");
    printf("|2.EGG ROLL                         |        40        |\n");
    printf("|3.CHICKEN ROLL                     |        60        |\n");
    printf("|4.MOTTON ROLL                      |        80        |\n");
    printf("|5.VEG THALI                        |       100        |\n");
    printf("|6.CHILLI PANEER                    |        90        |\n");
    printf("|7.SAHI PANEER                      |       120        |\n");
    printf("|8.CHICKEN CHAP                     |       150        |\n");
    printf("|9.CHICKEN BIRIYANI                 |       230        |\n");
    printf("|10.MOTTON BIRIYANI                 |       250        |\n");
    printf("+-----------------------------------+------------------+\n");
}

void stateorder(int n)
{
    char b[10000];
    int ump;
    do
    {
        printf("State appropriate number of plates: ");
        fgets(b, sizeof(b), stdin);
        strtok(b, "\n");
        fflush(stdin);
    } while (numcheck(b) != 1);
    sscanf(b, "%d", &ump);
    if (n == 1)
    {
        d1 = ump * 30;
        td1 += d1;
        p1 += ump;
        total += d1;
    }
    if (n == 2)
    {
        d2 = ump * 40;
        td2 += d2;
        p2 += ump;
        total += d2;
    }
    if (n == 3)
    {
        d3 = ump * 60;
        td3 += d3;
        p3 += ump;
        total += 80;
    }
    if (n == 4)
    {
        d4 = ump * 80;
        td4 += d4;
        p4 += ump;
        total += d4;
    }
    if (n == 5)
    {
        d5 = ump * 100;
        td5 += d5;
        p5 += ump;
        total += d5;
    }
    if (n == 6)
    {
        d6 = ump * 90;
        td6 += d6;
        p6 += ump;
        total += d6;
    }
    if (n == 7)
    {
        d7 = ump * 120;
        td7 += d7;
        p7 += ump;
        total += d7;
    }
    if (n == 8)
    {
        d8 = ump * 150;
        td8 += d8;
        p8 += ump;
        total += d8;
    }
    if (n == 9)
    {
        d9 = ump * 230;
        td9 += d9;
        p9 += ump;
        total += d9;
    }
    if (n == 10)
    {
        d10 = ump * 250;
        td10 += d10;
        p10 += ump;
        total += d10;
    }
}

int exorder()
{
    char a[100];
    int ump;
    while (1)
    {
        printf("Please state your order (CHOOSE BETWEEN 1 - 10)\n--> ");
        fgets(a, sizeof(a), stdin);
        strtok(a, "\n");
        fflush(stdin);
        if (numcheck(a) == 1)
        {
            sscanf(a, "%d", &ump);
            if (ump >= 1 && ump <= 10)
                break;
        }
    }
    return ump;
}

void order()
{
    char c;
    total = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, d9 = 0, d10 = 0;
    td1 = 0, td2 = 0, td3 = 0, td4 = 0, td5 = 0, td6 = 0, td7 = 0, td8 = 0, td9 = 0, td10 = 0;
    p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, p6 = 0, p7 = 0, p8 = 0, p9 = 0, p10 = 0;
    while (c != 'n' && c != 'N')
    {
        printmenu();
        stateorder(exorder());
        printf("Want to order anything else? (y/n)\n--> ");
        scanf(" %c", &c);
        fflush(stdin);
    }
    printbill();
}

void printbill()
{
    char x;
    do
    {
        printf("1.Want to pay the bill?\n2.Want to cancel your orders?\n(CHOOSE BETWEEN 1 and 2)\n--> ");
        scanf(" %c", &x);
        fflush(stdin);
    } while (x != '1' && x != '2');
    if (x == '1')
    {
        c[i].total = total;
        printf("\nHERE IS YOUR BILL\n");
        printf("\n**************************************");
        printf("\n              FOODY EXPRESS            \n");
        printf("(2/52)Central Road, Anandapuri, Barrackpore");
        printf("\n       foodyexpress2022@gmail.com       ");
        printf("\n              +91 988153691              ");
        printf("\n--------------------------------------\n");
        printf("Bill ID: %s\n", c[i].id);
        printf("Bill name: %s\n", c[i].name);
        printf("Phn no.: %s\n", c[i].phn);
        printf("Address: %s\n", c[i].add);
        printf("---------------------------------------");
        printf("\nITEMS              QTY   PRICE   TOTAL");
        printf("\n======================================");
        if (p1 != 0)
            printf("\n%s       %d      %d     %d", dish1, p1, r1, td1);
        if (p2 != 0)
            printf("\n%s            %d      %d     %d", dish2, p2, r2, td2);
        if (p3 != 0)
            printf("\n%s        %d      %d     %d", dish3, p3, r3, td3);
        if (p4 != 0)
            printf("\n%s         %d      %d     %d", dish4, p4, r4, td4);
        if (p5 != 0)
            printf("\n%s           %d     %d     %d", dish5, p5, r5, td5);
        if (p6 != 0)
            printf("\n%s       %d      %d     %d", dish6, p6, r6, td6);
        if (p7 != 0)
            printf("\n%s         %d     %d    %d", dish7, p7, r7, td7);
        if (p8 != 0)
            printf("\n%s        %d     %d    %d", dish8, p8, r8, td8);
        if (p9 != 0)
            printf("\n%s    %d     %d    %d", dish9, p9, r9, td9);
        if (p10 != 0)
            printf("\n%s     %d     %d    %d", dish10, p10, r10, td10);
        printf("\n======================================");
        printf("\nGRAND TOTAL                       %d\n", total);
        printf("Grand total in Words: ");
        convert(total);
        printf("\n--------------------------------------");
        printf("\n   YOUR ORDER WILL BE DELIVERED SOON");
        printf("\n              THANK YOU               ");
        printf("\n**************************************");
        if (i == 0)
        {
            FILE *fp;
            fp = fopen("Record.txt", "a");
            fprintf(fp, "******************************* REPORT %d ", day);
            switch (temp)
            {
            case 1:
                fprintf(fp, "Jan, ");
                break;
            case 2:
                fprintf(fp, "Feb, ");
                break;
            case 3:
                fprintf(fp, "Mar, ");
                break;
            case 4:
                fprintf(fp, "Apr, ");
                break;
            case 5:
                fprintf(fp, "May, ");
                break;
            case 6:
                fprintf(fp, "June, ");
                break;
            case 7:
                fprintf(fp, "July, ");
                break;
            case 8:
                fprintf(fp, "Aug, ");
                break;
            case 9:
                fprintf(fp, "Sep, ");
                break;
            case 10:
                fprintf(fp, "Oct, ");
                break;
            case 11:
                fprintf(fp, "Nov, ");
                break;
            case 12:
                fprintf(fp, "Dec, ");
                break;
            }
            fprintf(fp, "%d *******************************\n", year);
            fclose(fp);
        }
        record();
    }
    else
        printf("!!!CANCELLATION SUCCESSFULL!!!");
}

void convert(int n)
{
    j = 0;
    sprintf(r, "%d", n);
    l = strlen(r);
    while (r[j] != '\0')
    {
        if (l == 6)
        {
            if (r[j] - '0' != 0)
            {
                printf("%s ", single_digit[r[j] - '0']);
                printf("%s ", ten_power[l - 4]);
            }
        }
        if (l == 5)
        {
            if (r[j] - '0' != 0)
            {
                if (r[j] - '0' == 1)
                {
                    int sum = r[j] - '0' + r[j + 1] - '0';
                    printf("%s ", double_digit[sum]);
                    printf("%s ", ten_power[l - 4]);
                }
                else
                {
                    printf("%s ", tens_multiple[r[j] - '0']);
                    if (r[j + 1] - '0' != 0)
                    {
                        printf("%s ", single_digit[r[j + 1] - '0']);
                        printf("%s ", ten_power[l - 4]);
                    }
                    else
                        printf("%s ", ten_power[l - 4]);
                }
            }
        }
        if (l == 4)
        {
            if (r[j] - '0' != 0 && r[j - 1] - '0' == 0)
            {
                printf("%s ", single_digit[r[j] - '0']);
                printf("%s ", ten_power[l - 3]);
            }
            else
            {
                if (r[j] - '0' != 0)
                {
                    printf("%s ", single_digit[r[j] - '0']);
                    printf("%s ", ten_power[l - 3]);
                }
            }
        }
        if (l == 3)
        {
            if (r[j] - '0' != 0)
            {
                printf("%s ", single_digit[r[j] - '0']);
                printf("%s ", ten_power[l - 3]);
            }
        }
        if (l == 2)
        {
            if (r[j] - '0' != 0)
            {
                printf("%s ", tens_multiple[r[j] - '0']);
            }
        }
        l = l - 1;
        j++;
    }
}

void record()
{
    FILE *fp;
    fp = fopen("Record.txt", "a");
    fprintf(fp, "Customer id: %s", c[i].id);
    fprintf(fp, "\nCustomer name: %s", c[i].name);
    fprintf(fp, "\nCustomer Phn number: %s", c[i].phn);
    fprintf(fp, "\nCustomer address: %s", c[i].add);
    fprintf(fp, "\n----------------------------------------------------------------------");
    fprintf(fp, "\nDISH NAME            NUMBER OF PLATES             RATE          TOTAL");
    fprintf(fp, "\n======================================================================");
    if (p1 != 0)
        fprintf(fp, "\n%s                %d                     %d             %d", dish1, p1, r1, td1);
    if (p2 != 0)
        fprintf(fp, "\n%s                     %d                     %d             %d", dish2, p2, r2, td2);
    if (p3 != 0)
        fprintf(fp, "\n%s                 %d                     %d             %d", dish3, p3, r3, td3);
    if (p4 != 0)
        fprintf(fp, "\n%s                  %d                     %d             %d", dish4, p4, r4, td4);
    if (p5 != 0)
        fprintf(fp, "\n%s                    %d                    %d            %d", dish5, p5, r5, td5);
    if (p6 != 0)
        fprintf(fp, "\n%s                %d                     %d             %d", dish6, p6, r6, td6);
    if (p7 != 0)
        fprintf(fp, "\n%s                  %d                    %d            %d", dish7, p7, r7, td7);
    if (p8 != 0)
        fprintf(fp, "\n%s                 %d                    %d            %d", dish8, p8, r8, td8);
    if (p9 != 0)
        fprintf(fp, "\n%s             %d                    %d            %d", dish9, p9, r9, td9);
    if (p10 != 0)
        fprintf(fp, "\n%s              %d                    %d            %d", dish10, p10, r10, td10);
    fprintf(fp, "\n======================================================================");
    fprintf(fp, "\nGRAND TOTAL                                                      %d", total);
    fprintf(fp, "\n----------------------------------------------------------------------\n");
    fclose(fp);
}

void convert_file(int n)
{
    j = 0;
    sprintf(r, "%d", n);
    l = strlen(r);
    FILE *vp;
    vp = fopen("Record.txt", "a");
    while (r[j] != '\0')
    {
        if (l == 6)
        {
            if (r[j] - '0' != 0)
            {
                fprintf(vp, "%s ", single_digit[r[j] - '0']);
                fprintf(vp, "%s ", ten_power[l - 4]);
            }
        }
        if (l == 5)
        {
            if (r[j] - '0' != 0)
            {
                if (r[j] - '0' == 1)
                {
                    int sum = r[j] - '0' + r[j + 1] - '0';
                    fprintf(vp, "%s ", double_digit[sum]);
                    fprintf(vp, "%s ", ten_power[l - 4]);
                }
                else
                {
                    fprintf(vp, "%s ", tens_multiple[r[j] - '0']);
                    if (r[j + 1] - '0' != 0)
                    {
                        fprintf(vp, "%s ", single_digit[r[j + 1] - '0']);
                        fprintf(vp, "%s ", ten_power[l - 4]);
                    }
                    else
                        fprintf(vp, "%s ", ten_power[l - 4]);
                }
            }
        }
        if (l == 4)
        {
            if (r[j] - '0' != 0 && r[j - 1] - '0' == 0)
            {
                fprintf(vp, "%s ", single_digit[r[j] - '0']);
                fprintf(vp, "%s ", ten_power[l - 3]);
            }
            else
            {
                if (r[j] - '0' != 0)
                {
                    fprintf(vp, "%s ", single_digit[r[j] - '0']);
                    fprintf(vp, "%s ", ten_power[l - 3]);
                }
            }
        }
        if (l == 3)
        {
            if (r[j] - '0' != 0)
            {
                fprintf(vp, "%s ", single_digit[r[j] - '0']);
                fprintf(vp, "%s ", ten_power[l - 3]);
            }
        }
        if (l == 2)
        {
            if (r[j] - '0' != 0)
            {
                fprintf(vp, "%s \n", tens_multiple[r[j] - '0']);
            }
        }
        l = l - 1;
        j++;
    }
    fclose(vp);
}
