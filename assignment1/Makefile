all:camper date campsite tester category campground main

camper: Camper.cc Camper.h
	g++ -c Camper.cc
date: Date.cc Date.h
	g++ -c Date.cc
campsite: Campsite.cc Campsite.h Camper.cc Camper.h
	g++ -c Campsite.cc
tester: Tester.cc Tester.h
	g++ -c Tester.cc
category: Category.cc Category.h
	g++ -c Category.cc
campground: Campground.cc Campground.h Campsite.cc Campsite.h Camper.cc Camper.h
	g++ -c Campground.cc
main: Date.o Date.cc Date.h Tester.o Tester.cc Tester.h Category.o Category.cc Category.h Camper.o Camper.cc Camper.h Campsite.o Campsite.cc Campsite.h Campground.o Campground.cc Campground.h
	g++ -o main  main.cc Date.o Tester.o Category.o Camper.o Campsite.o Campground.o