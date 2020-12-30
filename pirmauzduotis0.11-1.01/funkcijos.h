#pragma once
#include "trycatch.h"
#include "baze.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
void ketvirta(int irasusk);
void nuskaitymas(string failas, vector <baze>& studentai);
void funkcija(string failas, vector <baze> studentai);
void pirma(vector <baze> studentai, vector <baze>& vargsiukai, vector <baze>& galvociai);
void padalinimostrategija(vector <baze>& studentai, vector <baze>& vargsiukai);
