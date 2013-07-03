#define DEFAULT_LIT_NUM 5

class Literal
{
public:
	int *appears;
	int appear_cnt,appear_max,state;

	Literal();
	~Literal();
	void init(int t);
	void add_appear(int cla);
};

class Clause
{
public:
	int *literals;
	int lit_cnt,lit_max,last_state;

	Clause();
	~Clause();
	void init();
	void add_literal(int lit);
};

class CNF
{
public:
	Clause *clauses;
	Literal *literals;
	int *cla;
	int lit_cnt,cla_cnt;

	CNF();
	~CNF();
	void init();
	void solver();
	void add_clause(int index);
	void sort_clause(int l,int r);
	void sort_literal(int l,int r);
private:
	bool comp_clause(int a,int b);
	bool comp_literal(int a,int b);
};