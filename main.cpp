#include <iostream>
#include <iomanip>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;


char plansza[6][6];
bool tab_czy_zajete[6][6];

void wypisanie_planszy();
void obracanie();
void krzyzyk();
void ruch_komputera();
bool warunek_wygrania_O();
bool warunek_wygrania_X();
int gra();
bool czy_dobre_dane(int a,int b);


int main()
{
    srand( time( NULL ) );

    gra();

    return 0;
}




void wypisanie_planszy()
{
    cout << "  cw. 4      cw. 1" << endl;

    int numeracja=6;
    for(int i=0;i<3;i++)
    {
        cout << numeracja << " ";

        for(int j=0;j<3;j++)
        {
            cout << "|" << plansza[i][j];
        }

        cout << "|    ";

        for(int j=3;j<6;j++)
        {
            cout << "|" << plansza[i][j];
        }

        cout << "|" << endl;
        numeracja--;
    }

    cout << "_____________________\n\n";

    for(int i=3;i<6;i++)
    {
        cout << numeracja << " ";

        for(int j=0;j<3;j++)
        {
            cout << "|" << plansza[i][j];
        }

        cout << "|    ";

        for(int j=3;j<6;j++)
        {
            cout << "|" << plansza[i][j];
        }

        cout << "|" << endl;
        numeracja--;
    }
    cout << "   A B C      D E F\n";
    cout << "  cw. 3      cw. 2" << endl;

}


void obracanie()
{
    char cwiartka;
    bool czy_dobre_dane=1;
    int tablica_ram[6][6];



    cout << "Ktora cwiartke chcesz obrocic?: \n";

    while(czy_dobre_dane)
    {
        cin >> cwiartka;

        if( cwiartka=='1' || cwiartka=='2' || cwiartka=='3' || cwiartka=='4')
        {
            switch(cwiartka)
            {
            case '1':

                for(int i=0;i<6;i++)
                    for(int j=0;j<6;j++)
                        tablica_ram[i][j]=plansza[i][j];

                plansza[0][3]=tablica_ram[2][3];
                plansza[0][4]=tablica_ram[1][3];
                plansza[0][5]=tablica_ram[0][3];
                plansza[1][5]=tablica_ram[0][4];
                plansza[2][5]=tablica_ram[0][5];
                plansza[2][4]=tablica_ram[1][5];
                plansza[2][3]=tablica_ram[2][5];
                plansza[1][3]=tablica_ram[2][4];

                tab_czy_zajete[0][3]=tablica_ram[2][3];
                tab_czy_zajete[0][4]=tablica_ram[1][3];
                tab_czy_zajete[0][5]=tablica_ram[0][3];
                tab_czy_zajete[1][5]=tablica_ram[0][4];
                tab_czy_zajete[2][5]=tablica_ram[0][5];
                tab_czy_zajete[2][4]=tablica_ram[1][5];
                tab_czy_zajete[2][3]=tablica_ram[2][5];
                tab_czy_zajete[1][3]=tablica_ram[2][4];
                czy_dobre_dane=0;
                break;

            case '2':

                for(int i=0;i<6;i++)
                    for(int j=0;j<6;j++)
                        tablica_ram[i][j]=plansza[i][j];

                plansza[3][3]=tablica_ram[5][3];
                plansza[3][4]=tablica_ram[4][3];
                plansza[3][5]=tablica_ram[3][3];
                plansza[4][5]=tablica_ram[3][4];
                plansza[5][5]=tablica_ram[3][5];
                plansza[5][4]=tablica_ram[4][5];
                plansza[5][3]=tablica_ram[5][5];
                plansza[4][3]=tablica_ram[5][4];

                tab_czy_zajete[3][3]=tablica_ram[5][3];
                tab_czy_zajete[3][4]=tablica_ram[4][3];
                tab_czy_zajete[3][5]=tablica_ram[3][3];
                tab_czy_zajete[4][5]=tablica_ram[3][4];
                tab_czy_zajete[5][5]=tablica_ram[3][5];
                tab_czy_zajete[5][4]=tablica_ram[4][5];
                tab_czy_zajete[5][3]=tablica_ram[5][5];
                tab_czy_zajete[4][3]=tablica_ram[5][4];

                czy_dobre_dane=0;
                break;

                //...
            case '3':
                for(int i=0;i<6;i++)
                    for(int j=0;j<6;j++)
                        tablica_ram[i][j]=plansza[i][j];

                plansza[3][0]=tablica_ram[5][0];
                plansza[3][1]=tablica_ram[4][0];
                plansza[3][2]=tablica_ram[3][0];
                plansza[4][2]=tablica_ram[3][1];
                plansza[5][2]=tablica_ram[3][2];
                plansza[5][1]=tablica_ram[4][2];
                plansza[5][0]=tablica_ram[5][2];
                plansza[4][0]=tablica_ram[5][1];

                tab_czy_zajete[3][0]=tablica_ram[5][0];
                tab_czy_zajete[3][1]=tablica_ram[4][0];
                tab_czy_zajete[3][2]=tablica_ram[3][0];
                tab_czy_zajete[4][2]=tablica_ram[3][1];
                tab_czy_zajete[5][2]=tablica_ram[3][2];
                tab_czy_zajete[5][1]=tablica_ram[4][2];
                tab_czy_zajete[5][0]=tablica_ram[5][2];
                tab_czy_zajete[4][0]=tablica_ram[5][1];

                czy_dobre_dane=0;
                break;

            case '4':

                for(int i=0;i<6;i++)
                    for(int j=0;j<6;j++)
                        tablica_ram[i][j]=plansza[i][j];

                plansza[0][0]=tablica_ram[2][0];
                plansza[0][1]=tablica_ram[1][0];
                plansza[0][2]=tablica_ram[0][0];
                plansza[1][2]=tablica_ram[0][1];
                plansza[2][2]=tablica_ram[0][2];
                plansza[2][1]=tablica_ram[1][2];
                plansza[2][0]=tablica_ram[2][2];
                plansza[1][0]=tablica_ram[2][1];

                tab_czy_zajete[0][0]=tablica_ram[2][0];
                tab_czy_zajete[0][1]=tablica_ram[1][0];
                tab_czy_zajete[0][2]=tablica_ram[0][0];
                tab_czy_zajete[1][2]=tablica_ram[0][1];
                tab_czy_zajete[2][2]=tablica_ram[0][2];
                tab_czy_zajete[2][1]=tablica_ram[1][2];
                tab_czy_zajete[2][0]=tablica_ram[2][2];
                tab_czy_zajete[1][0]=tablica_ram[2][1];

                czy_dobre_dane=0;
                break;


            }

        }
        else
        {
            cout << "Podaj nr od 1 do 4. \n";
        }
    }

}




void krzyzyk()
{
    string kolumna;
    int wiersz;
    int kolumna_int;
    int n=1;

    while(n==1)
    {
    cout << "Podaj nr wiersza, nastepnie litere odpowiadajaca kolumnie: ";
    cin >> wiersz >> kolumna;

    kolumna[0]=toupper(kolumna[0]);
    kolumna_int=kolumna[0]-65;


    if(tab_czy_zajete[6-wiersz][kolumna_int]==0 && czy_dobre_dane(6-wiersz,kolumna_int)==1)
    {

        plansza[6-wiersz][kolumna_int]='X';
        tab_czy_zajete[6-wiersz][kolumna_int]=1;
        n=0;
    }
    else
    {
        cout << "Zle dane." << endl;
    }

    }
}





void ruch_komputera()
{
    cout << "Teraz ruch wykonuje komputer.\n";

    bool n=1;
    int w, k, p;
    int tablica_ram[6][6];

    while(n)
    {
        w=rand() % 6;
        k=rand() % 6;
        p=rand() % 4 + 1;

        if(tab_czy_zajete[w][k]==0)
        {
            tab_czy_zajete[w][k]=1;
            plansza[w][k]='O';

            wypisanie_planszy();

            switch(p)
            {
            case 1:

                for(int i=0;i<6;i++)
                    for(int j=0;j<6;j++)
                        tablica_ram[i][j]=plansza[i][j];

                plansza[0][3]=tablica_ram[2][3];
                plansza[0][4]=tablica_ram[1][3];
                plansza[0][5]=tablica_ram[0][3];
                plansza[1][5]=tablica_ram[0][4];
                plansza[2][5]=tablica_ram[0][5];
                plansza[2][4]=tablica_ram[1][5];
                plansza[2][3]=tablica_ram[2][5];
                plansza[1][3]=tablica_ram[2][4];

                tab_czy_zajete[0][3]=tablica_ram[2][3];
                tab_czy_zajete[0][4]=tablica_ram[1][3];
                tab_czy_zajete[0][5]=tablica_ram[0][3];
                tab_czy_zajete[1][5]=tablica_ram[0][4];
                tab_czy_zajete[2][5]=tablica_ram[0][5];
                tab_czy_zajete[2][4]=tablica_ram[1][5];
                tab_czy_zajete[2][3]=tablica_ram[2][5];
                tab_czy_zajete[1][3]=tablica_ram[2][4];

                break;

            case 2:

                for(int i=0;i<6;i++)
                    for(int j=0;j<6;j++)
                        tablica_ram[i][j]=plansza[i][j];

                plansza[3][3]=tablica_ram[5][3];
                plansza[3][4]=tablica_ram[4][3];
                plansza[3][5]=tablica_ram[3][3];
                plansza[4][5]=tablica_ram[3][4];
                plansza[5][5]=tablica_ram[3][5];
                plansza[5][4]=tablica_ram[4][5];
                plansza[5][3]=tablica_ram[5][5];
                plansza[4][3]=tablica_ram[5][4];

                tab_czy_zajete[3][3]=tablica_ram[5][3];
                tab_czy_zajete[3][4]=tablica_ram[4][3];
                tab_czy_zajete[3][5]=tablica_ram[3][3];
                tab_czy_zajete[4][5]=tablica_ram[3][4];
                tab_czy_zajete[5][5]=tablica_ram[3][5];
                tab_czy_zajete[5][4]=tablica_ram[4][5];
                tab_czy_zajete[5][3]=tablica_ram[5][5];
                tab_czy_zajete[4][3]=tablica_ram[5][4];

                break;

                //...
            case 3:
                for(int i=0;i<6;i++)
                    for(int j=0;j<6;j++)
                        tablica_ram[i][j]=plansza[i][j];

                plansza[3][0]=tablica_ram[5][0];
                plansza[3][1]=tablica_ram[4][0];
                plansza[3][2]=tablica_ram[3][0];
                plansza[4][2]=tablica_ram[3][1];
                plansza[5][2]=tablica_ram[3][2];
                plansza[5][1]=tablica_ram[4][2];
                plansza[5][0]=tablica_ram[5][2];
                plansza[4][0]=tablica_ram[5][1];

                tab_czy_zajete[3][0]=tablica_ram[5][0];
                tab_czy_zajete[3][1]=tablica_ram[4][0];
                tab_czy_zajete[3][2]=tablica_ram[3][0];
                tab_czy_zajete[4][2]=tablica_ram[3][1];
                tab_czy_zajete[5][2]=tablica_ram[3][2];
                tab_czy_zajete[5][1]=tablica_ram[4][2];
                tab_czy_zajete[5][0]=tablica_ram[5][2];
                tab_czy_zajete[4][0]=tablica_ram[5][1];


                break;

            case 4:

                for(int i=0;i<6;i++)
                    for(int j=0;j<6;j++)
                        tablica_ram[i][j]=plansza[i][j];

                plansza[0][0]=tablica_ram[2][0];
                plansza[0][1]=tablica_ram[1][0];
                plansza[0][2]=tablica_ram[0][0];
                plansza[1][2]=tablica_ram[0][1];
                plansza[2][2]=tablica_ram[0][2];
                plansza[2][1]=tablica_ram[1][2];
                plansza[2][0]=tablica_ram[2][2];
                plansza[1][0]=tablica_ram[2][1];

                tab_czy_zajete[0][0]=tablica_ram[2][0];
                tab_czy_zajete[0][1]=tablica_ram[1][0];
                tab_czy_zajete[0][2]=tablica_ram[0][0];
                tab_czy_zajete[1][2]=tablica_ram[0][1];
                tab_czy_zajete[2][2]=tablica_ram[0][2];
                tab_czy_zajete[2][1]=tablica_ram[1][2];
                tab_czy_zajete[2][0]=tablica_ram[2][2];
                tab_czy_zajete[1][0]=tablica_ram[2][1];

                break;


            }

            n=0;
        }

    }
    wypisanie_planszy();
}


bool warunek_wygrania_O()
{
    int i_ter=0;
    int tab[36];

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            tab[i_ter]=plansza[i][j];
            i_ter++;
        }
    }

    int licznik=0;

    for(int i=0;i<12;i++)
    {
        for(int j=i;j<36;j+=6)
        {
            if(tab[j]=='O')
                licznik++;
            else
                licznik=0;

            if(licznik==5)
                return 1;
        }
    }

    licznik=0;

    for(int i=0;i<31;i+=6)
    {
        for(int j=i;j<i+6;j++)
        {
            if(tab[j]=='O')
                licznik++;
            else;
                licznik=0;

            if(licznik==5)
            return 1;
        }
    }

    licznik=0;


    for(int i=0;i<36;i+=7)
    {
        if(tab[i]=='O')
            licznik++;
        else
            licznik=0;

        if(licznik==5)
            return 1;
    }

    licznik=0;

     for(int i=1;i<36;i+=7)
    {
        if(tab[i]=='O')
            licznik++;

        if(licznik==5)
            return 1;
    }

    licznik=0;

     for(int i=6;i<36;i+=7)
    {
        if(tab[i]=='O')
            licznik++;

        if(licznik==5)
            return 1;
    }

    licznik=0;

     for(int i=5;i<31;i+=5)
    {
        if(tab[i]=='O')
            licznik++;
        else
            licznik=0;

        if(licznik==5)
            return 1;
    }

    licznik=0;

     for(int i=4;i<25;i+=5)
    {
        if(tab[i]=='O')
            licznik++;

        if(licznik==5)
            return 1;
    }

    licznik=0;

     for(int i=11;i<32;i+=5)
    {
        if(tab[i]=='O')
            licznik++;

        if(licznik==5)
            return 1;
    }



    return 0;

}


bool warunek_wygrania_X()
{
    int i_ter=0;
    int tab[36];

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            tab[i_ter]=plansza[i][j];
            i_ter++;
        }
    }

    int licznik=0;

    for(int i=0;i<12;i++)
    {
        for(int j=i;j<36;j+=6)
        {
            if(tab[j]=='X')
                licznik++;
            else
                licznik=0;

            if(licznik==5)
                return 1;
        }
    }

    licznik=0;

    for(int i=0;i<31;i+=6)
    {
        for(int j=i;j<i+6;j++)
        {
            if(tab[j]=='X')
                licznik++;
            else;
                licznik=0;

            if(licznik==5)
            return 1;
        }
    }

    licznik=0;


    for(int i=0;i<36;i+=7)
    {
        if(tab[i]=='X')
            licznik++;
        else
            licznik=0;

        if(licznik==5)
            return 1;
    }

    licznik=0;

     for(int i=1;i<36;i+=7)
    {
        if(tab[i]=='X')
            licznik++;

        if(licznik==5)
            return 1;
    }

    licznik=0;

     for(int i=6;i<36;i+=7)
    {
        if(tab[i]=='X')
            licznik++;

        if(licznik==5)
            return 1;
    }

    licznik=0;

     for(int i=5;i<31;i+=5)
    {
        if(tab[i]=='X')
            licznik++;
        else
            licznik=0;

        if(licznik==5)
            return 1;
    }

    licznik=0;

     for(int i=4;i<25;i+=5)
    {
        if(tab[i]=='X')
            licznik++;

        if(licznik==5)
            return 1;
    }

    licznik=0;

     for(int i=11;i<32;i+=5)
    {
        if(tab[i]=='X')
            licznik++;

        if(licznik==5)
            return 1;
    }



    return 0;
}

bool czy_dobre_dane(int a,int b)
{
    if(a>=0 && a<=5 && b>=0 && b<=5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int gra()
{
     wypisanie_planszy();
     int i=0;
     char stan_gry;
     cout << "Gre zaczyna Gracz!\n";

    while(i<36)
    {
        cout << "(Twoj ruch!)\n";
        krzyzyk();
        wypisanie_planszy();
        obracanie();
        wypisanie_planszy();

        if(warunek_wygrania_O()==1 && warunek_wygrania_X()==0)
        {
            cout << "Wygral Komputer\n";
            stan_gry='k';
        }
        if(warunek_wygrania_X()==1 && warunek_wygrania_O()==0)
        {
            cout << "Wygrales Gratulacje\n";
            stan_gry='k';
        }
        if(warunek_wygrania_O()==1 && warunek_wygrania_X()==1)
        {
            stan_gry='r';
        }

        switch(stan_gry)
        {
        case 'k':
            cout << "KONIEC GRY" << endl;
            return 0;
            break;
        case 'r':
            cout << "Remis!\nKONIEC GRY!" << endl;
            return 0;
            break;
        }

        cout << "(Ruch wykonuje Komputer)\n";
        ruch_komputera();

         if(warunek_wygrania_O()==1 && warunek_wygrania_X()==0)
        {
            cout << "Wygral Komputer\n";
            stan_gry='k';
        }
        if(warunek_wygrania_X()==1 && warunek_wygrania_O()==0)
        {
            cout << "Wygrales Gratulacje\n";
            stan_gry='k';
        }
        if(warunek_wygrania_O()==1 && warunek_wygrania_X()==1)
        {
            stan_gry='r';
        }

         switch(stan_gry)
        {
        case 'k':
            cout << "KONIEC GRY" << endl;
            return 0;
            break;
        case 'r':
            cout << "Remis!\nKONIEC GRY!" << endl;
            return 0;
            break;
        }
    }

        if(warunek_wygrania_O()==0 && warunek_wygrania_X()==0)
        cout << "Remis!\n";

}




