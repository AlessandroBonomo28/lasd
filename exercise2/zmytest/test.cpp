
#include "test.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"

#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"

#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"

#include <random>
#include <iostream>
#include <string>



using namespace std;
using namespace lasd;
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


string GetRandomString( uint n)
{
     static const char alphanum[] =
        "0123456789"
        "abcdefghijlmnopqrstuv";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, sizeof(alphanum) - 2);

    string s="";
    for (int i = 0; i < n; ++i)
        s += alphanum[dis(gen)];
    
    return s;
    
}
template<typename Data>
void UpperCase(Data& val, void* opt){
    for(int i=0;i<val.size();i++)
        val[i]=toupper(val[i]); 
}
template<typename Data>
void testStackVec(StackVec<Data>& stkvec)
{
    cout<<"Testing stack implementato con vettori "<<endl;
    char scelta;
    cout<<"Seleziona azione "<<\
        "\n1 print elemento in Top (lettura non distruttiva),"<<\
        "\n2 rimozione in top"<<\
        "\n3 rimuovi elemento in Top e stampa (TopNPop),"<<\
        "\n4 Inserisci elemento (Push),"<<\
        "\n5 print tutti gli elementi, dimensione fisica e logica"<<\
        "\n6 test di vuotezza e print dimensione,"<<\
        "\n7 svuotamento"<<endl;
    cin>>scelta;
    Data val;
    switch(scelta)
    {
        case '1':
            cout<<"Elemento in top lettura non distruttiva: "<<stkvec.Top()<<endl;
            break;
        case '2':
            stkvec.Pop();
            break;
        case '3':
            cout<<"lettura e rimozione elemento in top: "<< stkvec.TopNPop()<<endl;
            break;
        case '4':
            cout<<"push val: "<<endl;
            cin>>val;
            stkvec.Push(val);
            break;
        case '5':
            stkvec.Print();
            break;
        case '6':
            stkvec.Print();
            (stkvec.Empty()) ? cout<<"Vuota"<<endl : cout<<"Non vuota"<<endl;
            break;
        case '7':
            stkvec.Clear();
            cout<<"Svuotato"<<endl;
            break;
    }
}
template<typename Data>
void testStackLst(StackLst<Data>& stklist)
{
    cout<<"Testing stack implementato con lista "<<endl;
    char scelta;
    cout<<"Seleziona azione "<<\
        "\n1 print elemento in Top (lettura non distruttiva),"<<\
        "\n2 rimozione in top"<<\
        "\n3 rimuovi elemento in Top e stampa (TopNPop),"<<\
        "\n4 Inserisci elemento (Push),"<<\
        "\n5 print tutti gli elementi, dimensione "<<\
        "\n6 test di vuotezza e print dimensione,"<<\
        "\n7 svuotamento"<<endl;
    cin>>scelta;
    Data val;
    switch(scelta)
    {
        case '1':
            cout<<"Elemento in top lettura non distruttiva: "<<stklist.Top()<<endl;
            break;
        case '2':
            stklist.Pop();
            break;
        case '3':
            cout<<"lettura e rimozione elemento in top: "<< stklist.TopNPop()<<endl;
            break;
        case '4':
            cout<<"push val: "<<endl;
            cin>>val;
            stklist.Push(val);
            break;
        case '5':
            stklist.Print();
            break;
        case '6':
            stklist.Print();
            (stklist.Empty()) ? cout<<"Vuota"<<endl : cout<<"Non vuota"<<endl;
            break;
        case '7':
            stklist.Clear();
            cout<<"Svuotato"<<endl;
            break;
    }
}

void fillStackInt(Stack<int> &stk,uint  n)
{
    default_random_engine genx(random_device{}());
    uniform_int_distribution<int> distx(-1000,1000);
    
    for(int i=0;i<n;i++)
        stk.Push(distx(genx));
}
void fillStackFloat(Stack<float> &stk,uint  n)
{
    default_random_engine genx(random_device{}());
    uniform_real_distribution<float> distx(-1000,1000);
    
    for(int i=0;i<n;i++)
        stk.Push(distx(genx));
}

void fillStackString(StackVec<string> &stk,uint  n) 
{
    //push random string into stack
    default_random_engine genx(random_device{}());
    uniform_int_distribution<int> distx(5,10);
    //Vector<string> v = Vector<string>(n);
    for(int i=0;i<n;i++) 
    {
        //v[i] =GetRandomString(distx(genx));

        stk.Push(GetRandomString(distx(genx))); 
    }
    //stk =  std::move(StackVec<string>(v));
    //v.Clear();
}
void fillStackString(StackLst<string> &stk,uint  n) 
{
    //push random string into stack
    default_random_engine genx(random_device{}());
    uniform_int_distribution<int> distx(5,10);
    //Vector<string> v =  Vector<string>(n);
    for(int i=0;i<n;i++) 
    {
        //v[i] = GetRandomString(distx(genx));
        stk.Push(GetRandomString(distx(genx)));
    }
    //stk =  std::move(StackLst<string>(v));
    //v.Clear();
}
void scegliTipoStackLst()
{

    cout<<"che tipo di stack? (1) int (2) float (3) string"<<endl;
    char scelta;
    bool ripeti=true;
    cin>>scelta;
    uint n = AskInt("quanti elementi?");
    StackLst<int> stkInt = StackLst<int>();
    fillStackInt(stkInt,n);
    StackLst<float> stkFloat = StackLst<float>();
    fillStackFloat(stkFloat,n);
    StackLst<string> stkStr = StackLst<string>();
    fillStackString(stkStr,n);
    
    switch(scelta)
    {
        case '1':  
            while(ripeti)
            {
                testStackLst(stkInt);
                cout<<"Vuoi ripetere il test su int? (1) si (2) no"<<endl;
                cin>>scelta;
                if(scelta=='2')
                    ripeti=false;
            }
                
        break;
        case '2': 
            while(ripeti)
            {
                testStackLst(stkFloat);
                cout<<"Vuoi ripetere il test su float? (1) si (2) no"<<endl;
                cin>>scelta;
                if(scelta=='2')
                    ripeti=false;
            }
        break;
        case '3': 
            while(ripeti)
            {
                testStackLst(stkStr);
                cout<<"Vuoi ripetere il test su stringhe? (1) si (2) no"<<endl;
                cin>>scelta;
                if(scelta=='2')
                    ripeti=false;
            }
        break;
        default:  throw invalid_argument("invalid input.");
        break;
    }
}

void scegliTipoStackVec()
{

    cout<<"che tipo di stack? (1) int (2) float (3) string"<<endl;
    char scelta;
    bool ripeti=true;
    cin>>scelta;
    uint n = AskInt("quanti elementi?");

    StackVec<int> stkInt = StackVec<int>();
    fillStackInt(stkInt,n);
    StackVec<float> stkFloat = StackVec<float>();
    fillStackFloat(stkFloat,n);
    StackVec<string> stkStr = StackVec<string>();
    fillStackString(stkStr,n);
    
    switch(scelta)
    {
        case '1': 
            while(ripeti)
            {
                testStackVec(stkInt);
                cout<<"Vuoi ripetere il test su int? (1) si (2) no"<<endl;
                cin>>scelta;
                if(scelta=='2')
                    ripeti=false;
            }
        break;
        case '2':
            while(ripeti)
            {
                testStackVec(stkFloat);
                cout<<"Vuoi ripetere il test su float? (1) si (2) no"<<endl;
                cin>>scelta;
                if(scelta=='2')
                    ripeti=false;
            }
        break;
        case '3': 
        while(ripeti)
            {
                testStackVec(stkStr);
                cout<<"Vuoi ripetere il test su string? (1) si (2) no"<<endl;
                cin>>scelta;
                if(scelta=='2')
                    ripeti=false;
            }
        break;
        default: throw invalid_argument("invalid input.");
        break;
    }
}

void fillQueueInt(Queue<int> &stk,uint  n)
{
    default_random_engine genx(random_device{}());
    uniform_int_distribution<int> distx(-1000,1000);
    
    for(int i=0;i<n;i++)
        stk.Enqueue(distx(genx));
}
void fillQueueFloat(Queue<float> &stk,uint  n)
{
    default_random_engine genx(random_device{}());
    uniform_real_distribution<float> distx(-1000,1000);
    
    for(int i=0;i<n;i++)
        stk.Enqueue(distx(genx));
}
void fillQueueString(Queue<string> &stk,uint  n)
{
    for(int i=0;i<n;i++)
        stk.Enqueue(GetRandomString(n));
}
template<typename Data>
void testQueueVec(QueueVec<Data>& queuevec)
{
    cout<<"Testing queue implementata con vettori "<<endl;
    char scelta;
    cout<<"Seleziona azione "<<\
        "\n1 print elemento in testa (lettura non distruttiva),"<<\
        "\n2 rimozione in testa"<<\
        "\n3 rimuovi elemento in testa e stampa (HeadNDequeue),"<<\
        "\n4 Inserisci elemento (Enqueue),"<<\
        "\n5 print tutti gli elementi,"<<\
        "\n6 test di vuotezza e print, dimensione fisica e logica"<<\
        "\n7 svuotamento"<<endl;
    cin>>scelta;
    Data val;
    switch(scelta)
    {
        case '1':
            cout<<"Elemento in head lettura non distruttiva: "<<queuevec.Head()<<endl;
            break;
        case '2':
            queuevec.Dequeue();
            break;
        case '3':
            cout<<"lettura e rimozione elemento in head: "<< queuevec.HeadNDequeue()<<endl;
            break;
        case '4':
            cout<<"enqueue val: "<<endl;
            cin>>val;
            queuevec.Enqueue(val);
            break;
        case '5':
            queuevec.Print();
            break;
        case '6':
            queuevec.Print();
            (queuevec.Empty()) ? cout<<"Vuota"<<endl : cout<<"Non vuota"<<endl;
            break;
        case '7':
            queuevec.Clear();
            cout<<"Svuotato"<<endl;
            break;
    }
}
template<typename Data>
void testQueueLst(QueueLst<Data>& queuevec)
{
    cout<<"Testing queue implementata con lista "<<endl;
    char scelta;
    cout<<"Seleziona azione "<<\
        "\n1 print elemento in testa (lettura non distruttiva),"<<\
        "\n2 rimozione in testa"<<\
        "\n3 rimuovi elemento in testa e stampa (HeadNDequeue),"<<\
        "\n4 Inserisci elemento (Enqueue),"<<\
        "\n5 print tutti gli elementi,"<<\
        "\n6 test di vuotezza e print, dimensione "<<\
        "\n7 svuotamento"<<endl;
    cin>>scelta;
    Data val;
    switch(scelta)
    {
        case '1':
            cout<<"Elemento in head lettura non distruttiva: "<<queuevec.Head()<<endl;
            break;
        case '2':
            queuevec.Dequeue();
            break;
        case '3':
            cout<<"lettura e rimozione elemento in head: "<< queuevec.HeadNDequeue()<<endl;
            break;
        case '4':
            cout<<"enqueue val: "<<endl;
            cin>>val;
            queuevec.Enqueue(val);
            break;
        case '5':
            queuevec.Print();
            break;
        case '6':
            queuevec.Print();
            (queuevec.Empty()) ? cout<<"Vuota"<<endl : cout<<"Non vuota"<<endl;
            break;
        case '7':
            queuevec.Clear();
            cout<<"Svuotato"<<endl;
            break;
    }
}
void scegliTipoQueueLst()
{

    cout<<"che tipo di queue? (1) int (2) float (3) string"<<endl;
    char scelta;
    cin>>scelta;
    uint n = AskInt("quanti elementi?");

    QueueLst<int> queueInt = QueueLst<int>();
    fillQueueInt(queueInt,n);
    QueueLst<float> queueFloat = QueueLst<float>();
    fillQueueFloat(queueFloat,n);
    QueueLst<string> queueStr = QueueLst<string>();
    fillQueueString(queueStr,n);
    switch(scelta)
    {
        case '1':  testQueueLst(queueInt);
        break;
        case '2': testQueueLst(queueFloat);
        break;
        case '3': testQueueLst(queueStr);
        break;
        default:  throw invalid_argument("invalid input.");
        break;
    }
}

void scegliTipoQueueVec()
{

    cout<<"che tipo di queue? (1) int (2) float (3) string"<<endl;
    char scelta;
    bool ripeti = true;
    cin>>scelta;
    int n = AskInt("quanti elementi?");

    QueueVec<int> queueInt = QueueVec<int>();
    fillQueueInt(queueInt,n);
    QueueVec<float> queueFloat = QueueVec<float>();
    fillQueueFloat(queueFloat,n);
    QueueVec<string> queueStr = QueueVec<string>();
    fillQueueString(queueStr,n);
    switch(scelta)
    {
        case '1': 
            while(ripeti)
            {
                testQueueVec(queueInt);
                cout<<"Vuoi ripetere il test su int? (1) si (2) no"<<endl;
                cin>>scelta;
                if(scelta=='2')
                    ripeti=false;
            }
        break;
        case '2':
            while(ripeti)
            {
                testQueueVec(queueFloat);
                cout<<"Vuoi ripetere il test su float? (1) si (2) no"<<endl;
                cin>>scelta;
                if(scelta=='2')
                    ripeti=false;
            }
        break;
        case '3': 
            while(ripeti)
            {
                testQueueVec(queueStr);
                cout<<"Vuoi ripetere il test su string? (1) si (2) no"<<endl;
                cin>>scelta;
                if(scelta=='2')
                    ripeti=false;
            }
        break;
        default: throw invalid_argument("invalid input.");
        break;
    }
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
void testEx1()
{
    char scelta;
    bool ripeti;
    do
    {
        
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
                cout<<"La somma degli elementi minori di "<<val<<" ??: "<<acc<<endl;

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
                cout<<"La somma degli elementi minori di "<<val<<" ??: "<<acc<<endl;

                vec1.Map(&Raddoppia<float>,nullptr);
                cout<<"Vettore dopo raddoppiamento: ";
                vec1.Map(MapPrint<float>,nullptr);

                cout<<"Inserisci n"<<endl;
                cin>>val;
                acc = 0;
                vec1.Fold(MoltMaggN<float>,&val,&acc);
                cout<<"Il prodotto degli elementi maggori di "<<val<<" ??: "<<acc<<endl;

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
                cout<<"La concatenazione delle stringhe con lunghezza <= "<<val<<" ??: "<<acc<<endl;

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
                cout<<"La somma degli elementi minori di "<<val<<" ??: "<<acc<<endl;

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
                cout<<"La somma degli elementi minori di "<<val<<" ??: "<<acc<<endl;

                vec1.Map(&Raddoppia<float>,nullptr);
                cout<<"lista dopo raddoppiamento: ";
                vec1.Map(MapPrint<float>,nullptr);

                cout<<"Inserisci n"<<endl;
                cin>>val;
                acc = 0;
                vec1.Fold(MoltMaggN<float>,&val,&acc);
                cout<<"Il prodotto degli elementi maggori di "<<val<<" ??: "<<acc<<endl;

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
                cout<<"La concatenazione delle stringhe con lunghezza <= "<<val<<" ??: "<<acc<<endl;

                vec1.Map(&UpperCase<string>,nullptr);
                cout<<"lista dopo UpperCase: ";
                vec1.Map(&MapPrint<string>,nullptr);
            }
        }
         // chiedere se vuole continuare
        cout<<"Vuoi continuare? (1) si (2) no"<<endl;
        cin>>scelta;
        if(scelta == '1')ripeti = true;
        else ripeti = false;
    } while (ripeti);
}
void testEx2()
{
    bool ripeti;
    do
    {
        char scelta;
        cout<<"Che struttura desideri stack(1) o queue(2)?"<<endl;
        cin>>scelta;
        if(scelta == '1') // stack
        {
            scelta;
            cout<<"che tipo di stack? (1) vector implementation (2) list implementation"<<endl;
            
            cin>>scelta;
            if(scelta == '1')
            {
                scegliTipoStackVec();
            }
            else
            {
                scegliTipoStackLst();
            }
            
            
        }
        else // lista
        {
            scelta;
            cout<<"che tipo di queue? (1) vector implementation (2) list implementation"<<endl;
            cin>>scelta;
            if(scelta == '1')
            {
                scegliTipoQueueVec();
            }
            else
            {
                scegliTipoQueueLst();
            }
            
        }
        // chiedere se vuole continuare
        cout<<"Vuoi continuare? (1) si (2) no"<<endl;
        cin>>scelta;
        if(scelta == '1')ripeti = true;
        else ripeti = false;
    } while (ripeti);
}
void mytest()
{
    cout << "- Start of my test -" << endl;
    char scelta;
    cout<<" Vuoi eseguire l'esecizio 1? (vector-list) (1) si (2) no"<<endl;
    cin>>scelta;
    if(scelta =='1')testEx1();
    cout<<" Vuoi eseguire l'esecizio 2? (stack-queue) (1) si (2) no"<<endl;
    cin>>scelta;
    if(scelta =='1')testEx2();
    cout<<endl;
    cout << "- End of my test -" << endl;
}