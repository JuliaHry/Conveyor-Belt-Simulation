#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <time.h>	
#include <future>

using namespace std;

queue<double> TworzenieTasmaciagu()
{
    queue<double> Tasmaciag;

        for (int i = 0; i < 7; i++)
        {
            double liczba = double(1 + rand() % (100)) / 10;
            Tasmaciag.push(liczba);
        }
    return Tasmaciag;
}

void UsuwanieZTasmaciagu(queue<double>* Tasmaciag, double* a)
{
    if (!(*Tasmaciag).empty())
    {
        *a = (*Tasmaciag).front();
        (*Tasmaciag).pop();
    }
}

void DrukowanieTasmaciagu(queue<double> Tasmaciag)
{
    int k = Tasmaciag.size();
    cout << "   ";
    while (!Tasmaciag.empty())
    {
        cout << Tasmaciag.front() << ' ';
        Tasmaciag.pop();
    }
    cout << endl;
    cout << "<-";
    for (int i = 0; i < k; i++)
        cout << "----";
}

void OperacjeNaTasmaciagu(queue<double>* Tasmaciag, double* a)
{
  
    UsuwanieZTasmaciagu(Tasmaciag, a);

    double liczba = double(1 + rand() % (100)) / 10;
    (* Tasmaciag).push(liczba);

    cout << endl;
    if (!(*Tasmaciag).empty())
    {
        DrukowanieTasmaciagu(*Tasmaciag);
        cout << endl;
    }
    else cout << "Tasmaciag jest pusty";

}

class Samochod
{
    public:

    int Numer = 0;
    double Pojemnosc = 0;
    stack<double> Zawartosc;
    double AktualnaZajetosc = 0;

    void ZwiekszZajetosc(double x)
    {
        AktualnaZajetosc += x;
    }

    void DodajPrzedmiot(double x)
    {
        Zawartosc.push(x);
    }

    void ZczytajPrzedmiot()
    {
        cout << Zawartosc.top();
    }
};

void DrukujSamochod(stack<double> Zawartosc, int nr, double poj, double zaj)
{
    int k = Zawartosc.size();
    cout << 'n' << nr << " = " << poj << ':' << endl;
    cout << "Aktualna zajetosc: " << zaj << endl;
    cout << endl;
    cout << "/---|";
    while (!Zawartosc.empty())
    {
        cout << Zawartosc.top() << ' ';
        Zawartosc.pop();
    }
    cout << endl;
    cout << "|---|";
    for (int i = 0; i < k; i++)
        cout << "----";
    cout << endl;

    cout << "oo";
    for (int i = 0; i < k; i++)
        cout << "    ";
    cout << "oo" << endl;
   
    cout << endl;
}

void DodajSamochod(vector<Samochod>& NoweSamochody, int nr)
{
    Samochod NewSamochod;
    NewSamochod.Numer = nr;
    NewSamochod.Pojemnosc = double(12 + rand() % (10));
    NewSamochod.AktualnaZajetosc = 0;
    NoweSamochody.push_back(NewSamochod);
}

void DodajPrzedmiotDoSamochodu(vector<Samochod>& NoweSamochody, int* x, double* a)
{
    if ((NoweSamochody[*x].AktualnaZajetosc + (*a)) <= NoweSamochody[*x].Pojemnosc)
    {
        NoweSamochody[*x].DodajPrzedmiot(*a);
        NoweSamochody[*x].AktualnaZajetosc += (*a);
        (*a) = 0;
    }
}

void DodawaniePrzedmiotu(vector<Samochod>& NoweSamochody, double* a)
{
    int k = 0;
    for (int i = 0; (i < NoweSamochody.size()) && ((*a) != 0); i++)
    {
        DodajPrzedmiotDoSamochodu(NoweSamochody, &i, a);
        k++;
    }

    if ((*a) != 0) {
        DodajSamochod(NoweSamochody, NoweSamochody.size());
        DodajPrzedmiotDoSamochodu(NoweSamochody, &k, a);
    }
}

void DrukujSamochody(vector<Samochod> NoweSamochody)
{
    for (int i = 0; i < NoweSamochody.size(); i++)
    {
        DrukujSamochod(NoweSamochody[i].Zawartosc, i, NoweSamochody[i].Pojemnosc, NoweSamochody[i].AktualnaZajetosc);
    }
}


int main()
{

    srand(time(NULL));

    vector<Samochod> listaSamochodow;
    char n;
    cout << "Kliknij 's', aby utworzyc tasmaciag: " << endl;
    cin >> n;
    while (n != 's')
    {
        cout << "Kliknij 's', aby utworzyc tasmaciag: " << endl;
        cin >> n;
    }

     {
        future<queue<double>> Tasm = async(TworzenieTasmaciagu);
        queue<double> Tasmaciag = Tasm.get();
        DrukowanieTasmaciagu(Tasmaciag);
        cout << endl;
        int nr = 0;
        double a = 0;
        int x;
        int m = 1;


        while (m)
        {
            OperacjeNaTasmaciagu(&Tasmaciag, &a);
            x = 0;
            if (a != 0) {
                DodawaniePrzedmiotu(listaSamochodow, &a);
            }
            cout << endl;

            DrukujSamochody(listaSamochodow);

            cout << "Kliknij 'k', aby zakonczyc program lub dowolny klawisz, aby kontynuowac";
            cin >> n;
            if (n == 'k') m = 0;

            system("cls");
        }
    }
}