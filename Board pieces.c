#include<stdio.h>
#include<conio.h>
#include<string.h>
char a[9][9];
int i, j;
//Only Pawns can move, program does not stop
int* pos_row(char p, int row)
{
    int c[2];
    for(j=1; j<=8; j++)
            if(a[row][j] == p)
                {
                    c[0] = row;
                    c[1] = j;
                }
    return c;
}
int* pos_col(char p, int col)
{
    int c[2];
    for(i=1; i<=8; i++)
            if(a[i][col] == p)
                {
                    c[0] = i;
                    c[1] = col;
                }
    return c;
}
void show()
{
        for(i = 8; i>=1; i--)
        {
            for(j=1; j<=8; j++)
            {
                printf("%c\t", a[i][j]);
            }
         printf("\n");
        }
}
int rowcheck(int row, char p)
{
        int j;
        for(j = 1; j<=8; j++)
        {
            if(a[row][j]==p)
                return 1;
        }
        return 0;
}
int colcheck(int col, char p)
{
        int i, x=0;
        for(i = 1; i<=8; i++)
        {
            if(a[i][col]==p)
                x=1;
        }

    return x;
}
void main()
{

    for(i = 1; i<=8; i++)
        for(j=1; j<=8; j++)
        {
            a[i][j] = '_';
        }
    i = 2;
    for(j = 1; j<=8; j++)
        a[i][j] = 'P';
    i = 7;
    for(j = 1; j<=8; j++)
        a[i][j] = 'p';

    a[1][1] = 'R', a[8][1] = 'r', a[1][8] = 'R', a[8][8] = 'r';
    a[1][4] = 'Q', a[8][4] = 'q';
    a[1][5] = 'K', a[8][5] = 'k';
    a[1][2] = 'N', a[1][7] = 'N', a[8][2] = 'n', a[8][7] = 'n';
    a[1][3] = 'B', a[1][6] = 'B', a[8][3] = 'b', a[8][6] = 'b';


    show();

    char move[4] = " ", f, r, p;
    int *c, d, e, color = 1;

    while(move!= '0')
    {

    switch(color)
    {
    case 1:
        printf("White to move\n TYPE '0' TO STOP");
        printf("\n\nEnter your move  ");
        scanf("%s", &move);
        printf("%s", move);
        if(strlen(move)==2)
        {
            p = 'P';
            f = move[0];
            int file = f - '`';

            printf("%d\n",file);
            r = move[1];
            int rank = r - '0';
            printf("%d\n", rank);
            if(colcheck(file,p) == 1)
            {
                c = pos_col(p,file);
                a[rank][file]= p;
                d = c[0];
                e = c[1];
                a[d][e] = '_';
                show();
                color = 0;

            }
        }
        if(strlen(move)==3)
        {
            p = move[0];
            f = move[1];
            int file = f - '`';
            printf("%d\n",file);
            r = move[2];
            int rank = r - '0';
            printf("%d\n", rank);
            if(p == 'Q' || p == 'R' || p == 'B' || p == 'N'|| p== 'K')
            {
                if(colcheck(file,p) == 1)
                {
                    c = pos_col(p,file);
                    a[rank][file]= p;
                    d = c[0];
                    e = c[1];
                    a[d][e] = '_';
                    show();
                    color = 0;
                    break;
                }
            }

        }
        break;

    case 0:
        printf("Black to move\n TYPE '0' TO STOP");
        printf("\n\nEnter your move  ");
        scanf("%s", &move);
        if(strlen(move)==2)
        {
            p = 'p';
            f = move[0];
            int file = f - '`';
            printf("%d\n",file);
            r = move[1];
            int rank = r - '0';
            printf("%d\n", rank);
            if(colcheck(file,p) == 1)
            {
                c = pos_col(p,file);
                a[rank][file]= p;
                d = c[0];
                e = c[1];
                a[d][e] = '_';
                show();
                color =  1;
            }
        }
        if(strlen(move)==3)
        {
            p = move[0];
            f = move[1];
            int file = f - '`';
            printf("%d\n",file);
            r = move[2];
            int rank = r - '0';
            printf("%d\n", rank);
            if(p == 'q' || p == 'r' || p == 'b' || p == 'n'|| p== 'k')
            {
                if(colcheck(file,p) == 1)
                {
                    c = pos_col(p,file);
                    a[rank][file]= p;
                    d = c[0];
                    e = c[1];
                    a[d][e] = '_';
                    show();
                    color = 1;
                    break;
                }
            }

        }
    break;
    }

    }

}
