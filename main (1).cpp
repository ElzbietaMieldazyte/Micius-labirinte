#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dydis = 10;

void VaizduokLabirinta(const vector<vector<char>>& labirintas, int playerRow, int playerCol, int fishrow, int fishcol) {
    for (int i = 0; i < dydis; ++i) {
        for (int j = 0; j < dydis; ++j) {
        
            if (i == playerRow && j == playerCol) {
                cout << "\U0001F431" << " "; 
            } 
            else if(i==fishrow && j==fishcol){
            cout<<"\U0001F41F"<<" ";
            
            }
            else{
                cout << labirintas[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void movePlayer(vector<vector<char>>& labirintas, int& playerRow, int& playerCol, char direction) {
    switch(direction) {
        case 'w':
            if (playerRow > 0 && labirintas[playerRow - 1][playerCol] != '#') {
                labirintas[playerRow][playerCol] = ' ';
                playerRow--; 
            } 
            break;
        case 's': 
           
            if (playerRow < dydis - 1 && labirintas[playerRow + 1][playerCol] != '#') {
                labirintas[playerRow][playerCol] = ' ';
                playerRow++;
            } 
            break;
        case 'a':
            if (playerCol > 0 && labirintas[playerRow][playerCol - 1] != '#') {
                labirintas[playerRow][playerCol] = ' ';
                playerCol--;
            } 
            break;
        case 'd': 
            if (playerCol < dydis - 1 && labirintas[playerRow][playerCol + 1] != '#') {
                labirintas[playerRow][playerCol] = ' ';
                playerCol++;
            } 
            break;
    }
}

int main() {
cout<<"                                 /_____/ "<<endl;
cout<<"                                /  o   o   "<< endl;
cout<<"                               ( ==  ^  == )"<<endl;
cout<<"                                )         ("<<endl;
cout<<"                               (           )"<<endl;
cout<<"                              ( (  )   (  ) ))"<<endl;
cout<<"                              (__(__)___(__)__)"<<endl;
cout<<" "<<endl;
cout<<"    _.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._"<<endl;
cout<<".-'---      - ---     --     ---   -----   - --       ----  ----   -     ---`-."<<endl;
cout<<" )                                                                           ("<<endl;
cout<<"(                        Padėk Miciui gauti žuvytę!                           )"<<endl;
cout<<" )                                                                           ("<<endl;
cout<<"(                      [ SPAUSK s, KAD PADĖTUM MICIUI ]                     )"<<endl;
cout<<" )                                                                           ("<<endl;
cout<<"(___       _       _       _       _       _       _       _       _       ___)"<<endl;
cout<<"    (__  _) ( __ _) (__  _) (__ _ ) `-._.-' ( _ __) (_  __) (_ __ ) (_  __)"<<endl;
cout<<"    ( _ __) (_  __) (__ __) `-._.-'         `-._.-' (__ __) (__  _) (__ _ )"<<endl;
cout<<"    (_ ___) `-._.-'                                         `-._.-' (___ _)"<<endl;
cout<<"    `-._.-'                                                         `-._.-'"<<endl;
cout<<" "<<endl;

char a;
cin>>a;
while (true) {
        cin >> a;

        if (a == 's') {
            break;
        } 
        else {
            cout << "Spausk s..." << endl;
        }
    }
    system("clear");
    vector<vector<char>> labirintas = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int playerRow = 1; 
    int playerCol = 1;
    int fishrow=8;
    int fishcol=8;

    char move;
    while (true) {
        system("clear");
        VaizduokLabirinta(labirintas, playerRow, playerCol, fishrow, fishcol);

       
        cout << "Vesk Micių link žuvytės (w: į viršų, s: žemyn, a: kairė, d: dešinė): ";
        cin >> move;

        
        movePlayer(labirintas, playerRow, playerCol, move);

        if (playerRow==fishrow && playerCol==fishcol) {
           cout<<"    _.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._"<<endl;
cout<<".-'---      - ---     --     ---   -----   - --       ----  ----   -     ---`-."<<endl;
cout<<" )                                                                           ("<<endl;
cout<<"(                        Micius gavo žuvytę!                                  )"<<endl;
cout<<" )                                                                           ("<<endl;
cout<<"    (__  _) ( __ _) (__  _) (__ _ ) `-._.-' ( _ __) (_  __) (_ __ ) (_  __)"<<endl;
cout<<"    ( _ __) (_  __) (__ __) `-._.-'         `-._.-' (__ __) (__  _) (__ _ )"<<endl;
cout<<"    (_ ___) `-._.-'                                         `-._.-' (___ _)"<<endl;
cout<<"    `-._.-'                                                         `-._.-'"<<endl;
cout<<" "<<endl;
            break;
        }
    }

    return 0;
}








