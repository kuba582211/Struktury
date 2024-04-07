#include <iostream>
#include <iomanip>
#include <chrono>
#include <windows.h>
#include "DynamicArray.h"
#include "LinkedList.h"

using namespace std;
using namespace std::chrono;

void srodek(string text){
    int spacje =120-((120-text.length())/2);
    cout << setw(spacje)<<text;
}

string menu(){
    string wybor;
    srodek("Witaj w porownywaniu tablic oraz list jednokierunkowych.\n");
    srodek("Jaka funkcja cie interesuje?\n\n");
    srodek("Dodawanie elementow      Usuwanie elementow      Wyszukiwanie elementu\n");
    srodek("         1                       2                           3        \n");
    srodek("Wyjscie 'stop'\n");
    srodek("Wybor: ");
    cin>>wybor;
    if(wybor == "1"){
        srodek("Dodawanie na:\n");
        srodek("Poczatku Koncu Srodku\n");
        srodek("   1       2     3   \n");
        srodek("Wybor: ");
        cin>>wybor;
        return "1" + wybor;
    }else if(wybor == "2"){
        srodek("Usuwanie na:\n");
        srodek("Poczatku Koncu Srodku\n");
        srodek("   1       2     3   \n");
        srodek("Wybor: ");
        cin>>wybor;
        return "2" + wybor;
    }else if(wybor == "3"){
        return "3";
    }else if(wybor == "stop"){
        return "stop";
    }else{
        srodek("Blad argumentow!\n");
        srodek("Sproboj ponownie\n\n");
        return "-1";
    }
}

int main()
{
	DynamicArray tablica;
	LinkedList lista;
    string wybor = "-1";
    auto czas = 0;
    int czas_tabliica[10];
    int czas_lista[10];

    while(wybor=="-1"){
        wybor = menu();
        if(wybor == "stop")return 0;

        if(wybor=="11"){
            cout<<endl<<endl;
            srodek("Dodawanie na Poczatku\n");
            int index = 0;
            for(int j = 100;j<=51200;j = j*2){

                auto start = high_resolution_clock::now();
                for (int i = 0; i < j; i++) { tablica.addElement(i,0); }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_tabliica[index] = czas;
                index++;
                for (int i = j-1; i >= 0; i--){ tablica.removeElement(i); }
            }

            index = 0;
            for(int j = 100;j<=51200;j = j*2){

                auto start = high_resolution_clock::now();
                for (int i = 0; i < j; i++) { lista.addLinkAtStart(i); }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_lista[index] = czas;
                index++;
                for (int i = j-1; i >= 0; i--){ lista.removeLink(i); }
            }
        }else if(wybor=="12"){
            cout<<endl<<endl;
            srodek("Dodawanie na Koncu\n");
            int index = 0;
            for(int j = 100;j<=51200;j = j*2){

                auto start = high_resolution_clock::now();
                for (int i = 0; i < j; i++) { tablica.addElement(i); }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_tabliica[index] = czas;
                index++;
                for (int i = j-1; i >= 0; i--){ tablica.removeElement(i); }
            }

            index = 0;
            for(int j = 100;j<=51200;j = j*2){

                auto start = high_resolution_clock::now();
                for (int i = 0; i < j; i++) { lista.addLink(i); }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_lista[index] = czas;
                index++;
                for (int i = j-1; i >= 0; i--){ lista.removeLink(i); }
            }
        }else if(wybor == "13"){
            cout<<endl<<endl;
            srodek("Dodawanie w srodku\n");
            int index = 0;
            for(int j = 100;j<=51200;j = j*2){

                auto start = high_resolution_clock::now();
                for (int i = 0; i < j; i++) { tablica.addElement(i,i/2);}
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_tabliica[index] = czas;
                index++;
                for (int i = j-1; i >= 0; i--){ tablica.removeElement(i); }
            }
            index = 0;
            for(int j = 100;j<=51200;j = j*2){

                auto start = high_resolution_clock::now();
                for (int i = 0; i < j; i++) { lista.addLinkAfter(i,i/2);}
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_lista[index] = czas;
                index++;
                for (int i = j-1; i >= 0; i--){ lista.removeLink(0); }
            }

            //Dodawanie w œrodku dla listy

        }else if(wybor == "21"){
            cout<<endl<<endl;
            srodek("Usuwanie na Poczatku\n");
            int index = 0;
            for(int j = 100;j<=51200;j = j*2){

                for (int i = 0; i < j; i++) { tablica.addElement(i); }
                auto start = high_resolution_clock::now();
                for (int i = j-1; i >= 0; i--){ tablica.removeElement(0);}
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_tabliica[index] = czas;
                index++;
            }

            index = 0;
            for(int j = 100;j<=51200;j = j*2){

                for (int i = 0; i < j; i++) { lista.addLinkAtStart(i);}
                auto start = high_resolution_clock::now();
                for (int i = j-1; i >= 0; i--){ lista.removeLink(0); }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_lista[index] = czas;
                index++;
            }
        }else if(wybor == "22"){
            cout<<endl<<endl;
            srodek("Usuwanie na Koncu\n");
            int index = 0;
            for(int j = 100;j<=51200;j = j*2){

                for (int i = 0; i < j; i++) { tablica.addElement(i); }
                auto start = high_resolution_clock::now();
                for (int i = j-1; i >= 0; i--){ tablica.removeElement(i);}
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_tabliica[index] = czas;
                index++;
            }

            index = 0;
            for(int j = 100;j<=51200;j = j*2){

                for (int i = 0; i < j; i++) { lista.addLinkAtStart(i);}
                auto start = high_resolution_clock::now();
                for (int i = j-1; i >= 0; i--){ lista.removeLink(i); }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_lista[index] = czas;
                index++;
            }
        }else if(wybor == "23"){
            cout<<endl<<endl;
            srodek("Usuwanie ze Srodka\n");
            int index = 0;
            for(int j = 100;j<=51200;j = j*2){

                for (int i = 0; i < j; i++) { tablica.addElement(i); }
                auto start = high_resolution_clock::now();
                for (int i = j-1; i >= 0; i--){ tablica.removeElement(i/2);}
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_tabliica[index] = czas;
                index++;
            }

            index = 0;
            for(int j = 100;j<=51200;j = j*2){

                for (int i = 0; i < j; i++) { lista.addLinkAtStart(i);}
                auto start = high_resolution_clock::now();
                for (int i = j-1; i >= 0; i--){ lista.removeLink(i/2); }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                czas = duration.count();
                czas_lista[index] = czas;
                index++;
            }
        }
        if(wybor == "3"){
            cout<<endl;
            int element;
            int index =0;
            for (int i = 0; i < 51201; i++){tablica.addElement(i);}
            for (int i = 0; i < 51201; i++) {lista.addLink(i);}
            srodek("Wyniki pomiarow\n");
            srodek("Element                            Tablica                              Lista\n");
            for(element = 5120;element<=51200;element=element+5120){

                auto start = high_resolution_clock::now();
                element = tablica.findElement(element);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                auto start1 = high_resolution_clock::now();
                element = lista.findElement(element);
                auto stop1 = high_resolution_clock::now();
                auto duration1 = duration_cast<microseconds>(stop1 - start1);

                cout<<setw(28)<<element<<setw(34)<<duration.count()<<setw(35)<<duration1.count()<<"\n";
            }
                for (int i = 51200; i >= 0; i--){tablica.removeElement(i);}
                for (int i = 51200; i >= 0; i--){lista.removeLink(i);}
        }else{
            srodek("Wyniki pomiarow\n");
            srodek("Ilosc elementow                     Tablica                              Lista\n");
            int ilosc = 100;
            for(int i =0;i<10;i++){
                cout<<setw(30)<<ilosc<<setw(34)<<czas_tabliica[i]<<setw(35)<<czas_lista[i]<<"\n";
                ilosc = ilosc *2;
            }
        }
        wybor="-1";
    }
    return 0;
}
