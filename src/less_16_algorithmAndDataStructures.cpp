//============================================================================
// Name        : less_16_algorithmAndDataStructures.cpp
// Author      : andry antonenko
// IDE         : Eclipse IDE
// Description : lesson 16 of the algorithms and data structures course
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;
//----------------------------------------------------------------------------
//#define NDEBUG
#include <cassert>
//----------------------------------------------------------------------------
/*
1. Реализовать шифрование и расшифровку цезаря
с передаваемым в функцию сообщением и ключом.
*/

char* caesarEncryption(char *mes,const int length, const int key)
{
  assert(mes != nullptr);

  char *encrMes = nullptr;
  try {
    encrMes = new char[length];
  }
  catch (const std::exception&) {
    cout << "No memory allocated." << endl;
  }

  if(encrMes != nullptr)
  {
    for(int i = 0; i < length; i++)
    {
      encrMes[i] = mes[i]%128 + key;
    }
  }

  return encrMes;
}

char* caesarDecryption(char *enc,const int length, const int key)
{
  assert(enc != nullptr);

  char *mes = nullptr;
  try {
    mes = new char[length];
  }
  catch (const std::exception&) {
    cout << "No memory allocated." << endl;
  }

  if(mes != nullptr)
  {
    for(int i = 0; i < length; i++)
    {
      mes[i] = (enc[i] - key)%128;
    }
  }

  return mes;
}

void freeArrayChar(char *mes)
{
  if(mes != nullptr)
  {
    delete mes;
  }
}
//----------------------------------------------------------------------------
/*
2. Реализовать шифрование и расшифровку перестановками
с передаваемым в функцию сообщением и количеством столбцов.
*/

char* permutationEncryption(char *mes, const int length, const int numberColumns)
{
  assert(mes != nullptr);

  int numberRows = length / numberColumns;
  if(length % numberColumns != 0) numberRows++;
  int lenEncrMes = numberColumns*numberRows;
  char *encrMes = nullptr;
  try {
    encrMes = new char[lenEncrMes];
  }
  catch (const std::exception&) {
    cout << "No memory allocated." << endl;
  }

  if(encrMes != nullptr)
  {
    for(int i = 0; i < lenEncrMes; i++)
      encrMes[i] = 0;
    for(int i = 0; i < length; i++)
      encrMes[(i%numberColumns)*numberRows + i/numberColumns] = mes[i];
  }
  return encrMes;
}

char* permutationDecryption(char *enc,const int length, const int numberColumns)
{
  assert(enc != nullptr);

  char *mes = nullptr;

  int numberRows = length / numberColumns;
  if(length % numberColumns != 0) numberRows++;
  int lenDecrMes = numberColumns*numberRows;

  try {
    mes = new char[lenDecrMes];
  }
  catch (const std::exception&) {
    cout << "No memory allocated." << endl;
  }

  if(mes != nullptr)
  {
    for(int i = 0; i < lenDecrMes; i++)
      mes[i] = 0;
    for(int i = 0; i < lenDecrMes; i++)
      mes[(i%numberRows)*numberColumns + i/numberRows] = enc[i];
  }

  return mes;
}

void printMes(const char *mes, const int length)
{
  for(int i = 0; i < length; i++)
  {
    cout << "[";
    if(mes[i] == 0) cout << "_";
    else cout << mes[i];
    cout << "," << (int)mes[i] << "] ";
  }
  cout << endl;
}
//----------------------------------------------------------------------------
void task_1()
{
  cout << "Task 1\n" << endl;

  const int KEY = 3;
  char mes[] = "This is a message.";
  cout << mes << endl;
  char *enc = caesarEncryption(mes,strlen(mes),KEY);
  cout << enc << endl;
  char *decr = caesarDecryption(enc,strlen(enc),KEY);
  cout << decr << endl;

  freeArrayChar(enc);
  freeArrayChar(decr);
}
//----------------------------------------------------------------------------
void task_2()
{
  cout << "Task 2\n" << endl;

  const int NUMBER_COLUMNS = 3;
  char mes[] = "This is a secret message.";
  int len = strlen(mes);

  cout << mes << endl;

  int numberRows = len / NUMBER_COLUMNS;
  if(len % NUMBER_COLUMNS != 0) numberRows++;
  int lenEncMes = NUMBER_COLUMNS*numberRows;

  char *enc = permutationEncryption(mes,len,NUMBER_COLUMNS);
  printMes(enc,lenEncMes);
  char *decr = permutationDecryption(enc,lenEncMes,NUMBER_COLUMNS);
  printMes(decr,lenEncMes);
  cout << decr << endl;

  freeArrayChar(enc);
  freeArrayChar(decr);
}
//----------------------------------------------------------------------------
int main() {
//----------------------------------------------------------------------------
  // Task 1
  //*
  task_1();
  //*/
//----------------------------------------------------------------------------
  // Task 2
  //*
  task_2();
  //*/
//----------------------------------------------------------------------------
	return 0;
}
//----------------------------------------------------------------------------
