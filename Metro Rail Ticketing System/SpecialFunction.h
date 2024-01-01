/*
Group Members:
Shahriar Mahabub Oishik(Team Lead & Backend Developer)
ID: 2023-3-60-073
Pulok Akibuzzaman(Frontend Developer)
ID: 2023-3-60-051
Md. Ashik-Uz-Zaman(Debugger)
ID: 2023-3-60-074
*/
///----------------------------------------Input Functions----------------------------------------------------------------
#define MAX_PASSWORD_LENGTH 28
#define MAX_PNUM_LENGTH 11
#define MAX_BALANCE_LENGTH 15
#define MAX_CODE_LENGTH 35555

int PasswordInput(char password[]) {
    char pw[MAX_PASSWORD_LENGTH+1];
    int x = 0;

    while (1) {
        char ch = getch();

        if (ch == 13) {  // Enter key
            pw[x] = '\0';
            break;
        } else if (ch == 8) {  // Backspace
            if (x > 0) {
                x--;
                printf("\b \b");
                pw[x] = '\0';
            }
        } else if (ch == 9 || ch == 27 || ch == 127 || ch == 17) {  // Tab, Escape, Delete
            if (x > 0) {
                x--;
                pw[x] = '\0';
            }
        } else {
            if (x < MAX_PASSWORD_LENGTH - 1) {
                pw[x] = ch;
                printf("*");
                x++;
            }
        }
    }

    strcpy(password, pw);
    return 0;
}

int PNumInput(char PNum[]) {
    char pw[MAX_PNUM_LENGTH + 1];  // +1 for null terminator
    int x = 0;

    while (1) {
        char ch = getch();

        if (ch == 13) {  // Enter key
            pw[x] = '\0';
            break;
        } else if (ch == 8 && x > 0) {  // Backspace
            x--;
            pw[x] = '\0';
            printf("\b \b");
        } else if ((ch == 9 || ch == 27 || ch == 127 || ch == 17) ||
                   ((ch >= ':' && ch <= '~') || (ch >= 1 && ch <= '/'))) {
            // Tab, Escape, Delete, Ctrl key, and additional disallowed characters
            if (x > 0) {
                x--;
                pw[x] = '\0';
            }
        } else if (x < MAX_PNUM_LENGTH) {
            pw[x] = ch;
            printf("%c", pw[x]);
            x++;
        }
    }

    strcpy(PNum, pw);
    return 0;
}
int NameInput(char Name[])
{

    char pw[35];
    int x=0;
end:
    while(!((int)pw[x-1]==13))
    {
        pw[x] = getch();
        if((int)pw[x]==13)
        {
            pw[x]=0;
            break;
        }
        else if((int)pw[x]==8)
        {
            pw[x]=0;
            if(x>0)
            {
                pw[x-1]=0;
                x--;
                printf("\b \b");
                goto end;
            }
            else if(x=0)
            {
                printf("\b \b");
                goto end;
            }
            goto end;
        }
        else if((int)pw[x]==9 ||(int)pw[x]==27||(int)pw[x]==127||(int)pw[x]==17||((int)pw[x]>=1 && (int)pw[x]<=31)||((int)pw[x]>=33 && (int)pw[x]<=64)||((int)pw[x]>=91 && (int)pw[x]<=96)||((int)pw[x]>=123 && (int)pw[x]<=128))
        {
            pw[x]=0;
            x--;
            goto incrementx;

        }
        if(x<32)
        {
            printf("%c",pw[x]);
        }
        if(x>32)
        {
            pw[x]=0;
            x-=2;
        }
incrementx:
        x++;
    }
    pw[x] = '\0';
    strcpy(Name,pw);
}
void PasswordInputL(char password[], int Lim) {
    char pw[31];  // 30 characters + 1 null terminator
    int x = 0;

    while (1) {
        char ch = getch();

        if (ch == 13) {  // Enter key
            pw[x] = '\0';
            break;
        } else if (ch == 8 && x > 0) {  // Backspace
            printf("\b \b");
            pw[--x] = '\0';
        } else if ((ch == 9 || ch == 27 || ch == 127 || ch == 17) ||
                   (x < Lim && (ch >= 32 && ch <= 126))) {
            // Tab, Escape, Delete, Ctrl key, and allowed characters
            if (ch != 9 && ch != 27) {
                if (x < Lim) {
                    pw[x++] = ch;
                    printf("*");
                }
            }
        }
    }

    strcpy(password, pw);
}

int BalanceInput() {
    char pw[MAX_BALANCE_LENGTH + 1];  // +1 for null terminator
    int x = 0;

    while (1) {
        char ch = getch();

        if (ch == 13) {  // Enter key
            pw[x] = '\0';
            break;
        } else if (ch == 8 && x > 0) {  // Backspace
            printf("\b \b");
            pw[--x] = '\0';
        } else if ((ch == 9 || ch == 27 || ch == 127 || ch == 17) ||
                   (ch == '-' && x == 0) ||
                   (ch >= '0' && ch <= '9' && x < MAX_BALANCE_LENGTH)) {
            // Tab, Escape, Delete, Ctrl key, optional negative sign, and digits
            if (ch != 9 && ch != 27) {
                pw[x++] = ch;
                printf("%c", ch);
            }
        }
    }

    pw[x] = '\0';
    return atoi(pw);
}


void CodeInput(char Name[]) {
    char pw[MAX_CODE_LENGTH + 1];  // +1 for null terminator
    int x = 0;

    while (1) {
        char ch = getch();

        if (ch == 13) {  // Enter key
            pw[x] = '\0';
            break;
        } else if (ch == 8 && x > 0) {  // Backspace
            printf("\b \b");
            pw[--x] = '\0';
        } else if ((ch == 9 || ch == 27 || ch == 127 || ch == 17) ||
                   ((ch < 1 || (ch > 31 && ch < 33) || ch > 128) && x > 0)) {
            // Tab, Escape, Delete, Ctrl key, and disallowed characters
            printf("\b \b");
            x = (x > 0) ? x - 1 : 0;
        } else if (isalpha(ch) && x < MAX_CODE_LENGTH) {
            pw[x++] = toupper(ch);
            putchar(ch);
        }
    }

    pw[x] = '\0';
    strcpy(Name, pw);
}

///--------------------------------------------------------------Code Conversion Function--------------------------------------------------
int CodeConvNum(char a[])
{
    int x=0;
    if(!strcmp(a,"AFN"))
    {
        x=18;
    }
    else if(!strcmp(a,"KRL"))
    {
        x=19;
    }
    else if(!strcmp(a,"MGB"))
    {
        x=17;
    }
    else if(!strcmp(a,"KRJ"))
    {
        x=15;
    }
    else if(!strcmp(a,"TSC"))
    {
        x=16;
    }
    else if(!strcmp(a,"UTR"))
    {
        x=20;
    }
    else if(!strcmp(a,"MDS"))
    {
        x=21;
    }
    return x;
}



int CodeConv(char a[],char destination[])
{
    if(!strcmp(a,"AFN"))
    {
        strcpy(destination,"Aftabnagar");
    }
    else if(!strcmp(a,"KRL"))
    {
        strcpy(destination,"Kuril");
    }
    else if(!strcmp(a,"MGB"))
    {
        strcpy(destination,"Mogbazar");
    }
    else if(!strcmp(a,"KRJ"))
    {
        strcpy(destination,"Keranigonj");
    }
    else if(!strcmp(a,"TSC"))
    {
        strcpy(destination,"TSC");
    }
    else if(!strcmp(a,"UTR"))
    {
        strcpy(destination,"Uttara");
    }
    else if(!strcmp(a,"MDS"))
    {
        strcpy(destination,"Mirpur DOHS");
    }
    else
    {
        strcpy(destination,"Doesn't Exist");
    }
}

///------------------------------------------------------------Total Fare Function-------------------------------------------------
#define PER_STATION_FEE 10
int TFare(char DCode[],char OCode[],int numT)
{
    int des=0,ori=0,StationTravel=0,TotalFare=0,countdes=0,countori=0;
    des=CodeConvNum(DCode);
    ori=CodeConvNum(OCode);
    int route[7]= {15,16,17,18,19,20,21};
    while(!(des==route[countdes]))
    {
        countdes++;
    }
    while(!(ori==route[countori]))
    {
        countori++;
    }
    if(ori<des)
    {
        StationTravel= -1*(ori-des);
    }
    else if(ori>des)
    {
        StationTravel =(ori-des);
    }
    else
    {
        StationTravel=0;
    }
    TotalFare= StationTravel*PER_STATION_FEE*numT;
    return TotalFare;
}

int getTime(int predate,char Date[]){
    time_t currentTime = time(NULL)+(predate * 24 * 60 * 60);

    if (currentTime == -1) {
        perror("Error getting time");
        return 1;
    }
    struct tm *localTime = localtime(&currentTime);
    if (localTime == NULL) {
        perror("Error converting to local time");
        return 1;
    }
    sprintf(Date,"%02d-%02d-%04d %02d:%02d:%02d",
           localTime->tm_mday,        // day of the month
           localTime->tm_mon + 1,     // months (0-11, so add 1)
           localTime->tm_year + 1900, // years since 1900
           localTime->tm_hour,        // hours
           localTime->tm_min,         // minutes
           localTime->tm_sec);        // seconds
}
