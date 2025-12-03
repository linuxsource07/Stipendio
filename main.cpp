// NOTE: Fare un programma che salva gli stipendi di ogni dipendente di un'azienda in un file di testo.
//       Il programma deve permettere di aggiungere, visualizzare e cercare gli stipendi
//       aggiungendo i nomi e cognomi dei dipendenti.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string filename = "stipendi.txt";
    int choice;

    while (true)
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Aggiungi stipendio\n";
        cout << "2. Visualizza stipendi\n";
        cout << "3. Cerca stipendi di un dipendente\n";
        cout << "4. Esci\n";
        cout << "Scegli un'opzione: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string nome, cognome;
            cout << "Inserisci il nome del dipendente: ";
            cin >> nome;
            cout << "Inserisci il cognome del dipendente: ";
            cin >> cognome;

            double stipendio;
            cout << "Inserisci lo stipendio da aggiungere: ";
            cin >> stipendio;

            ofstream outfile(filename, ios::app);
            if (!outfile)
            {
                cout << "Errore apertura file!\n";
                break;
            }

            outfile << nome << " " << cognome << " " << stipendio << endl;
            outfile.close();

            cout << "Stipendio aggiunto con successo.\n";
            break;
        }

        case 2:
        {
            ifstream infile(filename);
            if (!infile)
            {
                cout << "Errore apertura file o file inesistente.\n";
                break;
            }

            cout << "\n=== STIPENDI SALVATI ===\n";
            string nome, cognome;
            double stipendio;

            while (infile >> nome >> cognome >> stipendio)
            {
                cout << "Dipendente: " << nome << " " << cognome
                     << " | Stipendio: " << stipendio << endl;
            }

            infile.close();
            break;
        }

        case 3:
        {
            string searchNome, searchCognome;
            cout << "Inserisci il nome del dipendente da cercare: ";
            cin >> searchNome;
            cout << "Inserisci il cognome del dipendente da cercare: ";
            cin >> searchCognome;

            ifstream infile(filename);
            if (!infile)
            {
                cout << "Errore apertura file.\n";
                break;
            }

            bool found = false;
            string nome, cognome;
            double stipendio;

            cout << "\n=== RISULTATI DELLA RICERCA ===\n";

            while (infile >> nome >> cognome >> stipendio)
            {
                if (nome == searchNome && cognome == searchCognome)
                {
                    cout << "Stipendio: " << stipendio << endl;
                    found = true;
                }
            }

            infile.close();

            if (!found)
                cout << "Nessuno stipendio trovato per " << searchNome << " " << searchCognome << ".\n";

            break;
        }

        case 4:
            cout << "Uscita dal programma.\n";
            return 0;

        default:
            cout << "Opzione non valida. Riprova.\n";
            break;
        }
    }
}
