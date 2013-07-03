#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include "cnf.h"
using namespace std;

void Literal::init(int t)
{
	state=0;
	appear_cnt=0;
	appear_max=t+10;
	appears=new int[appear_max];
}

Literal::~Literal()
{
	delete []appears;
}

void Literal::add_appear(int cla)
{
	if (appear_cnt==appear_max)
	{
		int *temp=appears;
		appear_max*=2;
		appears=new int[appear_max];
		for (int i=0;i<appear_cnt;i++)
			appears[i]=temp[i];
		appears[appear_cnt]=cla;
		appear_cnt++;
		delete []temp;
	}
	else
	{
		appears[appear_cnt]=cla;
		appear_cnt++;
	}
}

void Clause::init()
{
	literals=new int[DEFAULT_LIT_NUM];
	lit_max=DEFAULT_LIT_NUM;
	lit_cnt=0;
	last_state=0;
}

Clause::~Clause()
{
	delete []literals;
}

void Clause::add_literal(int lit)
{
	if (lit_cnt==lit_max)
	{
		int *temp=literals;
		lit_max*=2;
		literals=new int[lit_max];
		for (int i=0;i<lit_cnt;i++)
			literals[i]=temp[i];
		literals[lit_cnt]=lit;
		lit_cnt++;
		delete []temp;
	}
	else
	{
		literals[lit_cnt]=lit;
		lit_cnt++;
	}
}

void CNF::init()
{
	char ch,s[5],buf[256];
	int i,t;
	while (cin>>ch&&ch!='p')
		cin.getline(buf,256);
	cin>>s>>lit_cnt>>cla_cnt;
	t=cla_cnt/lit_cnt;
	literals=new Literal[lit_cnt+10];
	for (i=1;i<=lit_cnt;i++)
		literals[i].init(t);
	cla=new int[cla_cnt+10];
	for (i=0;i<cla_cnt;i++)
		cla[i]=i;
	clauses=new Clause[cla_cnt+10];
	for (i=0;i<cla_cnt;i++)
		add_clause(i);
}

void CNF::add_clause(int index)
{
	int lit;
	clauses[index].init();
	while (scanf("%d",&lit)!=EOF&&lit!=0)
	{
		clauses[index].add_literal(lit);
		literals[abs(lit)].add_appear(index);
	}
}

bool CNF::comp_clause(int a,int b)
{
	return (clauses[a].lit_cnt<clauses[b].lit_cnt);
}

void CNF::sort_clause(int l,int r)
{
	int i,min,temp;
	min=l;
	for (i=l+1;i<r;i++)
	{
		if (clauses[cla[i]].lit_cnt<clauses[cla[min]].lit_cnt)
			min=i;
	}
	temp=cla[min];
	cla[min]=cla[l];
	cla[l]=temp;
}

bool CNF::comp_literal(int a,int b)
{
	return (literals[a].appear_cnt<literals[b].appear_cnt);
}

void CNF::sort_literal(int l,int r)
{
	int i,min,temp;
	min=l;
	for (i=l+1;i<r;i++)
	{
		if (literals[i].appear_cnt<literals[min].appear_cnt)
			min=i;
	}
	temp=cla[min];
	cla[min]=cla[l];
	cla[l]=temp;
}

void CNF::solver()
{
	int c=0;
	sort_clause(0,cla_cnt);
	while(c>=0)
	{
		clauses[c].last_state++;
		if (clauses[c].last_state>clauses[c].lit_cnt)
		{

		}
	}
}
