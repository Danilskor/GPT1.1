#pragma once

#include "Book.h"
#include "../Common/Input.h"
#include "../Common/Constants/Consts.h"
#include "Rectangle_Lab3.h"
#include "Time_Lab3.h"
#include "Flight_Lab3.h"
#include "Route.h"
#include <iostream>

void Lab3();

void DemoBook();
void WriteBookInConsole(Book& book);
void ReadBookFromConsole(string& name, int& year, int& pages, 
	int& numberOfAuthors, string*& authors);
Book* FindBookByAuthor(Book* books, int booksCount, string author);

void DemoRectangleWithPoint();

void DemoFlightWithTime();
void WriteFlightToConsole(cFlight* flight);
void WriteTimeToConsole(cTime* time);
cTime GetFlightTimeMinutes(cFlight* flight);

void DemoRoute();
void WriteRouteInCounsole(Route& route);
void ReadRouteFromConsole(int& number, int& timeAveregeMinutes, int& frequencyMinutes,
	int& stopsCount, string*& stops);
Route* FindRouteByStop(Route* routes, int routesCount, string stopName);