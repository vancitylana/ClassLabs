#pragma once
#include "form.h"
	class pravlenie :public gosudarstvo
{
public:
	pravlenie();
	void play();
};
class polit_rejim :public gosudarstvo
{
public:
    polit_rejim();
};
class ystroistvo :public gosudarstvo
{
public:
	ystroistvo();
	void play();
	void play(int i);
};
class monarchy :public pravlenie
{
public:
	monarchy();
	void play();
};
class republic :public pravlenie
{
public:
	republic();
	void play();
};
class totalitarism :public polit_rejim
{
public:
	totalitarism();
};
class avtoritarism :public polit_rejim
{
public:
	avtoritarism();
};
class democratic :public polit_rejim
{
public:
	democratic();
};
class federation :public ystroistvo
{
public:
	federation();
	void play();
};
class confederation :public ystroistvo
{
public:
	confederation();
	void play();
	void play(int n);
};
class unitarnoe :public ystroistvo
{
public:
	unitarnoe();
	void play();
};