

#include <iostream>
#include "iomanip"
#include "string"
using namespace std;

int horizontalCoord;
int verticalCoord;

bool input_check_coordinate(string &gamer, int array[][3]) {
  unsigned char numH;
  unsigned char numV;
  int count = 0;
  while (count < 5) {
    cout << "-----------------------" << endl
         << gamer << ", input horizontal coordinate: ";
    cin >> numH;
    cout << gamer << ",   input vertical coordinate: ";
    cin >> numV;
    if (numH < '1' || numH > '3' || numV < '1' || numV > '3') {
      cout << "<<<<<<<<<< Enter Error! >>>>>>>>>>" << endl;
      count++;
      continue;
    } else {
      horizontalCoord = static_cast<int>(numH - '0');
      verticalCoord = static_cast<int>(numV - '0');
      if (array[horizontalCoord - 1][verticalCoord - 1] != 0) {
        cout << "<<< The place is taken! Error! >>>" << endl;
        count++;
        continue;
      } else return true;
    }
  }
  return false;
}
void print_boardGame(char array[][6]) {
  cout << "     Game Board " << endl
       << "-----------------------" << endl;
  for (int i = 0; (i < 4); i++) {
    for (int j = 0; j < 6; j++) {
      cout << setw(3) << array[i][j];
    }
    cout << endl;
  }
}

int check_sum(int array[][3]) {
  int sum1 = 0;
  int sum2 = 0;
  int sum3 = 0;
  int sum4 = 0;
  int sum5 = 0;
  for (int i = 0; i < 3; i++) {
    sum4 += array[i][i];
    sum5 += array[i][2 - i];
    for (int j = 0; j < 3; j++) {
      sum1 += array[i][j];
      sum2 += array[j][i];
      sum3 += array[i][j];
    }
    if (sum1 == 15 || sum2 == 15 || sum4 == 15 || sum5 == 15) return 15;
    if (sum1 == 9 || sum2 == 9 || sum4 == 9 || sum5 == 9) return 9;
    if (sum3 == 35) return 35;
    sum1 = 0;
    sum2 = 0;
  }
  return -1;
}

int checkVertical(int number) {
  if (number == 2) {
    number = 3;
  } else if (number == 3) {
    number = 5;
  }
  return number;
}

bool check_winner(int sum) {
  if (sum == 9) {
    cout << "-----------------------" << endl
         << "Winner is Gamer < X > !" << endl
         << "#######################" << endl;
    return true;
  }
  if (sum == 15) {
    cout << "-----------------------" << endl
         << "Winner is Gamer < O > !" << endl
         << "#######################" << endl;
    return true;
  }
  if (sum == 35) {
    cout << "-----------------------" << endl
         << " We don`t have winner. " << endl
         << "#######################" << endl;
    return true;
  }
  return false;
}
int main() {
  char boardGame[4][6]
      {
          {' ', '1', ' ', '2', ' ', '3'},
          {'1', '?', '|', '?', '|', '?'},
          {'2', '?', '|', '?', '|', '?'},
          {'3', '?', '|', '?', '|', '?'}
      };
  print_boardGame(boardGame);
  string gamer_X = "Gamer < X >";
  string gamer_O = "Gamer < O >";
  int fieldGame[3][3]{};
  do {
    if (!(input_check_coordinate(gamer_X, fieldGame)))
      ::exit(0);
    fieldGame[horizontalCoord - 1][verticalCoord - 1] = 3;
    verticalCoord = checkVertical(verticalCoord);
    boardGame[horizontalCoord][verticalCoord] = 'X';
    print_boardGame(boardGame);
    int winner = check_sum(fieldGame);
    if (check_winner(winner)) break;
//--------------------------------------------------------------
    if (!(input_check_coordinate(gamer_O, fieldGame)))
      ::exit(0);
    fieldGame[horizontalCoord - 1][verticalCoord - 1] = 5;
    verticalCoord = checkVertical(verticalCoord);
    boardGame[horizontalCoord][verticalCoord] = 'O';
    print_boardGame(boardGame);
    winner = check_sum(fieldGame);
    if (check_winner(winner)) break;
  } while (true);
}


