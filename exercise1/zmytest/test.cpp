
#include "test.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include <random>
#include <iostream>
#include <string>



using namespace std;
int AskInt(string msg)
{
    int d;
    cout<<msg;
    cin>>d;
    return d;
}

template<typename Data>
void Raddoppia(Data & n, void* opt){
    n*=2;
}
template<typename Data>
void Concat(const Data& val, const void* value, void* acc){
    if(val.size()<=*(int*)value){
        (*(string*)acc) += val;
    } 
}

template<typename Data>
void MoltMaggN(const Data & n, const void* value, void* acc){   
    if(n>*(float*)value)
     *(float*)acc *= n;
}
template<typename Data>
void MapPrint(const Data& n, void* opt) {
  cout << n << " ";
}

template<typename Data>
void Square(Data & n, void* opt){
    n*=n;
}
void SommaMinN(const int & n, const void* value, void* acc){
    if(*((int*) value)>n)
        *(int*)acc+=n;
}


string GetRandomString(int len)
{
    static const char alphanum[] =
        "0123456789"
        "abcdefghijlmnopqrstuv";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);

    string s;
    for (int i = 0; i < len; ++i)
        s += alphanum[dis(gen)];
    
    return s;
}
template<typename Data>
void UpperCase(Data& val, void* opt){
    for(int i=0;i<val.size();i++)
        val[i]=toupper(val[i]); 
}


template <typename Data>
void testVettore( lasd::Vector<Data> vec1)
{
    char scelta;
    cout<<"Seleziona azione "<<\
        "\n1 print elemento in testa,"<<\
        "\n2 print elemento in coda,"<<\
        "\n3 print elemento n,"<<\
        "\n4 print tutti gli elementi,"<<\
        "\n5 cerca un elemento nell'array,"<<\
        
        "\n6 clear (distruzione)"<<endl;
    cin>>scelta;
    Data val;
    bool found;
    switch(scelta)
    {
        case '1':
            cout<<"Elemento in testa: "<<vec1[0]<<endl;
        break;
        case '2':
            cout<<"Elemento in coda: "<<vec1[vec1.Size()-1]<<endl;
        break;
        case '3':
            vec1[AskInt("Inserisci indice")];
            
        break;
        case '4':
            cout<<"Tutti gli elementi: ";
            vec1.Map(&MapPrint<Data>,nullptr);
            cout<<endl;
        break;
        case '5':
            found = false;
            cout<<"Inserisci valore da cercare: ";
            cin>>val;
            for(int i=0;i<vec1.Size();i++)
                if(vec1[i]==val)
                {
                    found=true;
                    cout<<"Elemento trovato in posizione "<<i<<endl;
                }
            if(!found)
                cout<<"Elemento non trovato"<<endl;        
            cout<<endl;
        break;
        case '6':
            vec1.Clear();
            cout<<"Vettore distrutto"<<endl;
        break;
        default:
        break;
    }
}
template <typename Data>
void testLista( lasd::Vector<Data> vec1)
{
    char scelta;
    cout<<"Seleziona azione "<<\
        "\n1 print elemento in testa,"<<\
        "\n2 print elemento in coda,"<<\
        "\n3 print elemento n,"<<\
        "\n4 print tutti gli elementi,"<<\
        "\n5 cerca un elemento nell'array,"<<\
        
        "\n6 clear (distruzione)"<<endl;
    cin>>scelta;
    Data val;
    bool found;
    switch(scelta)
    {
        case '1':
            cout<<"Elemento in testa: "<<vec1[0]<<endl;
        break;
        case '2':
            cout<<"Elemento in coda: "<<vec1[vec1.Size()-1]<<endl;
        break;
        case '3':
            vec1[AskInt("Inserisci indice")];
            
        break;
        case '4':
            cout<<"Tutti gli elementi: ";
            vec1.Map(&MapPrint<Data>,nullptr);
            cout<<endl;
        break;
        case '5':
            found = false;
            cout<<"Inserisci valore da cercare: ";
            cin>>val;
            for(int i=0;i<vec1.Size();i++)
                if(vec1[i]==val)
                {
                    found=true;
                    cout<<"Elemento trovato in posizione "<<i<<endl;
                }
            if(!found)
                cout<<"Elemento non trovato"<<endl;        
            cout<<endl;
        break;
        case '6':
            vec1.Clear();
            cout<<"Vettore distrutto"<<endl;
        break;
        default:
        break;
    }
}


void mytest()
{
    cout << "- Start of my test -" << endl;
    bool ripeti;
    do
    {
        char scelta;
        cout<<"Che struttura desideri array(1) o lista(2)?"<<endl;
        cin>>scelta;
        if(scelta == '1') // array
        {
            scelta;
            cout<<"che tipo di vettore? (1) int (2) float (3) string"<<endl;
            cin>>scelta;
            if(scelta == '1')
            {
                int n = AskInt("Inserisci il numero di elementi: ");
                lasd::Vector<int> vec1(n);
                
                default_random_engine genx(random_device{}());
                uniform_int_distribution<int> distx(-1000,1000);

                for(int i=0;i<n;i++)
                    vec1[i] = distx(genx);

                cout<<"Vettore creato"<<endl;
                vec1.Map(&MapPrint<int>,nullptr);

                // test vector int
                testVettore<int>(vec1);

                int val;
                cout<<"Inserisci il valore di n: "<<endl;
                cin>>val;
                int acc = 0;
                vec1.Fold(SommaMinN,&val,&acc);
                cout<<"La somma degli elementi minori di "<<val<<" è: "<<acc<<endl;

                vec1.Map(&Raddoppia<int>,nullptr);
                cout<<"Vettore dopo raddoppiamento: ";
                vec1.Map(&MapPrint<int>,nullptr);
            }
            else if(scelta == '2')
            {
                int n = AskInt("Inserisci il numero di elementi: ");
                lasd::Vector<float> vec1(n);
                
                default_random_engine genx(random_device{}());
                uniform_real_distribution<float> distx(-1000,1000);

                for(int i=0;i<n;i++)
                    vec1[i] = distx(genx);

                cout<<"Vettore creato"<<endl;
                vec1.Map(&MapPrint<float>,nullptr);

                // test vector float
                testVettore<float>(vec1);

                float val;
                cout<<"Inserisci il valore di n: "<<endl;
                cin>>val;
                float acc = 0;
                vec1.Fold(SommaMinN,&val,&acc);
                cout<<"La somma degli elementi minori di "<<val<<" è: "<<acc<<endl;

                vec1.Map(&Raddoppia<float>,nullptr);
                cout<<"Vettore dopo raddoppiamento: ";
                vec1.Map(MapPrint<float>,nullptr);

                cout<<"Inserisci n"<<endl;
                cin>>val;
                acc = 0;
                vec1.Fold(MoltMaggN<float>,&val,&acc);
                cout<<"Il prodotto degli elementi maggori di "<<val<<" è: "<<acc<<endl;

                vec1.Map(Square<float>,nullptr);
                cout<<"Vettore dopo square: ";
                vec1.Map(&MapPrint<float>,nullptr);
            }
            else
            {
                lasd::Vector<string> vec1;
                int n = AskInt("Inserisci il numero di elementi: ");

                for(int i=0;i<n;i++)
                    vec1[i] = GetRandomString(n);
                
                cout<<"Vettore creato"<<endl;
                vec1.Map(&MapPrint<string>,nullptr);

                // test vector string
                testVettore<string>(vec1);

                int val;
                cout<<"Inserisci la lunghezza massima delle stringhe da concatenare: "<<endl;
                cin>>val;
                string acc = "";
                vec1.Fold(&Concat<string>,&val,&acc);
                cout<<"La concatenazione delle stringhe con lunghezza <= "<<val<<" è: "<<acc<<endl;

                vec1.Map(&UpperCase<string>,nullptr);
                cout<<"Vettore dopo UpperCase: ";
                vec1.Map(&MapPrint<string>,nullptr);
            }
        }
        else // lista
        {
            scelta;
            cout<<"che tipo di lista? (1) int (2) float (3) string"<<endl;
            cin>>scelta;
            if(scelta == '1')
            {
                int n = AskInt("Inserisci il numero di elementi: ");
                lasd::List<int> vec1(n);
                
                default_random_engine genx(random_device{}());
                uniform_int_distribution<int> distx(-1000,1000);

                for(int i=0;i<n;i++)
                    vec1[i] = distx(genx);
                cout<<"lista creata"<<endl;
                vec1.Map(&MapPrint<int>,nullptr);
                // test list int
                testLista<int>(vec1);

                cout<<"lista creata"<<endl;
                vec1.Map(&MapPrint<int>,nullptr);

                

                int val;
                cout<<"Inserisci il valore di n: "<<endl;
                cin>>val;
                int acc = 0;
                vec1.Fold(SommaMinN,&val,&acc);
                cout<<"La somma degli elementi minori di "<<val<<" è: "<<acc<<endl;

                vec1.Map(&Raddoppia<int>,nullptr);
                cout<<"lista dopo raddoppiamento: ";
                vec1.Map(&MapPrint<int>,nullptr);
            }
            else if(scelta == '2')
            {
                int n = AskInt("Inserisci il numero di elementi: ");
                lasd::List<float> vec1(n);
                
                default_random_engine genx(random_device{}());
                uniform_real_distribution<float> distx(-1000,1000);

                for(int i=0;i<n;i++)
                    vec1[i] = distx(genx);
                
                cout<<"lista creata"<<endl;
                vec1.Map(&MapPrint<int>,nullptr);
                // test list float
                testLista<float>(vec1);
                
                float val;
                cout<<"Inserisci il valore di n: "<<endl;
                cin>>val;
                float acc = 0;
                vec1.Fold(SommaMinN,&val,&acc);
                cout<<"La somma degli elementi minori di "<<val<<" è: "<<acc<<endl;

                vec1.Map(&Raddoppia<float>,nullptr);
                cout<<"lista dopo raddoppiamento: ";
                vec1.Map(MapPrint<float>,nullptr);

                cout<<"Inserisci n"<<endl;
                cin>>val;
                acc = 0;
                vec1.Fold(MoltMaggN<float>,&val,&acc);
                cout<<"Il prodotto degli elementi maggori di "<<val<<" è: "<<acc<<endl;

                vec1.Map(Square<float>,nullptr);
                cout<<"lista dopo square: ";
                vec1.Map(&MapPrint<float>,nullptr);
            }
            else
            {
                lasd::List<string> vec1;
                int n = AskInt("Inserisci il numero di elementi: ");

                for(int i=0;i<n;i++)
                    vec1[i] = GetRandomString(n);
                cout<<"lista creata"<<endl;
                vec1.Map(&MapPrint<string>,nullptr);
                // test list string
                testLista<string>(vec1);
                
                int val;
                cout<<"Inserisci la lunghezza massima delle stringhe da concatenare: "<<endl;
                cin>>val;
                string acc = "";
                vec1.Fold(&Concat<string>,&val,&acc);
                cout<<"La concatenazione delle stringhe con lunghezza <= "<<val<<" è: "<<acc<<endl;

                vec1.Map(&UpperCase<string>,nullptr);
                cout<<"lista dopo UpperCase: ";
                vec1.Map(&MapPrint<string>,nullptr);
            }
        }

    } while (ripeti);
    cout<<endl;
    cout << "- End of my test -" << endl;
}