#include <stdio.h>
#include <stdlib.h>


/**
 * Cell final values
*/
short cVal[3][3][3][3];
/**
 * Cell possible values
*/
short cPos[3][3][3][3][9];
/**
 * Total number of scans are limit to 100
*/
int attempt=0;

/**
 * Loop for all 81 cells to load it with initial values
 */
void read();
/**
 * Assign one sell with initial values
 */
void init();
/**
 * Scans all cells to check if there is a cell with only one possible value
 */
void scan();
/**
 * Prints out the result
 */
void solve();
/**
 * Assign the found value to the cell and remove this value 
 * from the possible values of the other related cells.
 */
void putVal(short a,short b,short c,short d, short v);
short checkCellPos(short a,short b,short c,short d);

int main (void) 
{ 
    init();
    read();
    scan();
    solve();
    printf("\n\nNumber of attempts: %d \n\n", attempt);
    return(0);
}

void read()
{
    FILE *fptr;
    fptr = fopen("./puzzle.txt","r");
    short bv,sv,bh,sh,c;
    for(bv=0;bv<3;bv++)
    {
        for(sv=0;sv<3;sv++)
        {
            for(bh=0;bh<3;bh++)
            {
                for(sh=0;sh<3;sh++)
                {
                    if((c = fgetc(fptr)) == '-') continue;
                    // convert last parameters char to short before passing 
                    putVal(bv,sv,bh,sh,(c-'0'));
                }
            }
        }
    }
    fclose(fptr);
    printf("\n");
};

void scan()
{
    if(attempt>100) goto endof;
    int t;
    short bv,sv,bh,sh,found=0;
    attempt++;
    for(bv=0;bv<3;bv++)
    {
        for(sv=0;sv<3;sv++)
        {
            for(bh=0;bh<3;bh++)
            {
                for(sh=0;sh<3;sh++)
                {
                    if(cVal[bv][sv][bh][sh]>0) continue;
                    t = checkCellPos(bv,sv,bh,sh);
                    if(t>0)
                    {
                        putVal(bv,sv,bh,sh,t);
                        found++;
                    }
                }
            }
        }
    }
    if(found>0) scan();
    endof:;
};

void solve()
{
    printf("\n");
    short bv,sv,bh,sh;
    for(bv=0;bv<3;bv++)
    {
        for(sv=0;sv<3;sv++)
        {
            printf("\n-----------------\n");
            for(bh=0;bh<3;bh++)
            {
                for(sh=0;sh<3;sh++)
                {
                    printf("%d|",cVal[bv][sv][bh][sh]);
                }
            }
        }
    }
};

void init()
{
    short bv,sv,bh,sh,i;
    for(bv=0;bv<3;bv++)
    {
        for(sv=0;sv<3;sv++)
        {
            for(bh=0;bh<3;bh++)
            {
                for(sh=0;sh<3;sh++)
                {
                    cVal[bv][sv][bh][sh] = 0;
                    for(i=0; i<9; i++)
                    {
                        cPos[bv][sv][bh][sh][i] = 1;
                    }
                }
            }
        }
    }
};

void putVal(short a,short b,short c,short d, short v)
{
    cVal[a][b][c][d] = v;
    
    int x,y;
    // Make other possibilities zero
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            cPos[a][b][x][y][(v-1)] = 0; // horizontal
            cPos[x][y][c][d][(v-1)] = 0; // vertical
            cPos[a][x][c][y][(v-1)] = 0; // big square
        }
    }
};

short checkCellPos(short a,short b,short c,short d)
{
    short i, r=0, p=0;
    for(i=0;i<9;i++)
    {
        if(cPos[a][b][c][d][i]==1)
        {
            r=i;
            p++;
        }
    }
    if(p==1)
    {
        return r+1;
    }
    else
    {
        return 0;
    }
}