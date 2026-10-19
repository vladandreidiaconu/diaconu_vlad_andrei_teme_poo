
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Hotel
{
private:
    const int id;
    string denumire;
    int nr_camere;
    float* pret_camere;

public:
    static int nr_hoteluri;

    Hotel() : id(++nr_hoteluri)
    {
        this->denumire = "Default";
        this->nr_camere = 0;
        this->pret_camere = nullptr;
    }

    Hotel(int id, string denumire, int nr_camere, float* pret_camere) : id(++nr_hoteluri)
    {
        this->denumire = denumire;
        this->nr_camere = nr_camere;
        this->pret_camere = new float[nr_camere];

        for (int i = 0; i < this->nr_camere; i++)
        {
            this->pret_camere[i] = pret_camere[i];
        }
    }
    void afisare_hotel()
    {
        cout << endl << "Id: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Numar de camere: " << this->nr_camere;
        
        if (this->nr_camere > 0)
        {
            cout << endl << "Preturi camere: ";

            for (int i = 0; i < this->nr_camere - 1; i++)
            {
                cout << this->pret_camere[i] << " lei, ";
            }

            cout << this->pret_camere[this->nr_camere - 1] << " lei.";
        }

        cout << endl;
    }

    ~Hotel()
    {
        if (this->pret_camere != nullptr)
        {
            delete[] this->pret_camere;
        }
    }
};

int Hotel::nr_hoteluri = 0;

int main()
{
    Hotel hDefault;
    hDefault.afisare_hotel();

    float* pret_camere = new float[4] {500, 750, 1000, 2000};

    Hotel* pBucuresti = new Hotel(2, "Hotel Bucuresti", 4, pret_camere);
    pBucuresti->afisare_hotel();

    delete pBucuresti;
    delete[] pret_camere;

    if (Hotel::nr_hoteluri == 1)
    {
        cout << endl << "Am construit un hotel!" << endl;
    }
    else
    {
        cout << endl << "Am construit " << Hotel::nr_hoteluri << " hoteluri!" << endl;
    }
    return 0;
}
