#include "Hang.h"
Hangman::Hangman()
{
    jucator = 0;
    highscore = 0;
    greseli = 0;
    cuvant = 0;
    reper = 0;

}
ostream& operator<<(ostream& out, const Hangman& s) {
    out << s.jucator << ": " << s.highscore;

    return out;
}
istream& operator>>(istream& in, Hangman& s) {
    int nr = 0;
    srand((unsigned)time(0));

    int result = 1 + (rand() % 5);
    int incercari;
    string pp3;

    while (!in.eof())
    {

        pp3 = "";
        nr++;
        cout << endl;
        char* pp = new char[50];
        in >> pp;

        in >> incercari;
        pp3 = pp;


        char* pd = &pp3[0];


        if (nr == result)
        {

            s.setcuvant(pd);
            s.setgreseala(incercari);
            break;
        }
    }
    cout << "size == " << pp3.size() << "\n";
    char* pp2 = new char[pp3.size()];
    //cout << "pp2= " << pp2 << "\n";
    char* cleanArray = new char[pp3.size()];
    memset(cleanArray, 0, 100);
    memset(pp2, 0, 100);
    strncpy(pp2, cleanArray, pp3.size());
    for (int i = 0; i < pp3.size(); i++)
    {      // *(pp2 + i) = '_';
        pp2[i] = '_';
        //cout << pp2[i]<<' ';
    }
    //cout << "\npp2= " << pp2 << "\n";
    s.setreper(pp2);
    cout << " reper= " << s.reper << endl;
    cout << endl;
    return in;
}


Hangman& Hangman::operator=(const Hangman& s) {

    if (this != &s)
    {
        this->cuvant = new char[strlen(cuvant) + 1];
        strcpy(this->cuvant, s.cuvant);
        this->greseli = 0;
        this->reper = new char[strlen(cuvant) + 1];
        for (int i = 0; i < strlen(cuvant) + 1; i++)
            *(reper + i) = '_';
    }
    return *this;
}
void Hangman::greseala(Hangman& s)
{
    s.scadincercari();

    if (s.greseli == 7)
        cout << "ai pierdut" << endl;
    if (strncmp(s.cuvant, s.reper, strlen(s.cuvant) + 1) == 0)
        cout << "ai castigat" << endl;
}


void Hangman::input(Hangman& s)
{
    bool ok = false;
    char t;
    cout << "Dati litera ";
    cin >> t;
    for (int i = 0; i < strlen(s.cuvant) + 1; i++)
    {

        if (s.cuvant[i] == t)
        {
            s.reper[i] = t;
            ok = true;
        }
    }

    if (ok == false)
    {
        s.greseala(s);
        scor();
    }
    else
        s.highscore++;
    s.check();
}

void Hangman::check()
{
    if (greseli == 0)
    {
        cout << " ___________    " << endl;
        cout << " |              " << endl;
        cout << " |              " << endl;
        cout << " |              " << endl;
        cout << " |              " << endl;
        cout << "_|______________" << endl;
    }
    else  if (greseli == 1)
    {

        cout << " ___________    " << endl;
        cout << " |         |}   " << endl;
        cout << " |              " << endl;
        cout << " |              " << endl;
        cout << " |              " << endl;
        cout << "_|______________" << endl;
    }
    else  if (greseli == 2)
    {
        cout << " ___________    " << endl;
        cout << " |         |}   " << endl;
        cout << " |         O    " << endl;
        cout << " |              " << endl;
        cout << " |              " << endl;
        cout << "_|______________" << endl;
    }
    else  if (greseli == 3)
    {
        cout << " ___________    " << endl;
        cout << " |         |}   " << endl;
        cout << " |       \\ O    " << endl;
        cout << " |              " << endl;
        cout << " |              " << endl;
        cout << "_|______________" << endl;
    }
    else  if (greseli == 4)
    {

        cout << " ___________    " << endl;
        cout << " |         |}   " << endl;
        cout << " |       \\ O / " << endl;
        cout << " |              " << endl;
        cout << " |              " << endl;
        cout << "_|______________" << endl;
    }
    else  if (greseli == 5)
    {

        cout << " ___________    " << endl;
        cout << " |         |}   " << endl;
        cout << " |       \\ O / " << endl;
        cout << " |         |    " << endl;
        cout << " |              " << endl;
        cout << "_|______________" << endl;
    }
    else  if (greseli == 6)
    {

        cout << " ___________    " << endl;
        cout << " |         |}   " << endl;
        cout << " |       \\ O / " << endl;
        cout << " |         |    " << endl;
        cout << " |        /     " << endl;
        cout << "_|______________" << endl;
    }
    else
    {

        cout << " ___________    " << endl;
        cout << " |         |}   " << endl;
        cout << " |       \\ O / " << endl;
        cout << " |         |    " << endl;
        cout << " |        / \\  " << endl;
        cout << "_|______________" << endl;
    }
}

void Hangman::consola()
{
    check();
    do
    {
        afiseazacuv();
        afiseazagreseli();
        input(*this);

    } while (this->greseli < 7 && strncmp(cuvant, reper, strlen(cuvant) + 1) != 0);

}
int main()
{
    ifstream f("cuvinte.txt");

    Hangman h;
    f >> h;

    h.arata();
    cout << endl;
    h.consola();
    cout << endl;
    cout << h;
    cout << endl;
    return 0;
}