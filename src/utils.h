#ifndef UTILS_H
#define UTILS_H

#include <limits>
#include <string>
#include <iostream>

using namespace std;

int safeReadInt();
double safeReadDouble();
string safeReadLine();
void clearScreen(); // Метод для очистки экрана
void waitForEnter(); // Аналог задержки

#endif