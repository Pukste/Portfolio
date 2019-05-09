#include <iostream>

class Big_Data {
public:
	
	
	Big_Data(unsigned varaus)  {
		_buf = malloc(varaus);
		_varaus = varaus;
	}
	
	
	Big_Data const operator = (Big_Data const& second){
		
		return *this;
	}
	~Big_Data() {
	
		free(_buf);
	}
private:
	void* _buf = nullptr;
	unsigned _varaus = 0;

};

int main()
{
   
	Big_Data a(1024);
	Big_Data b(1024);
	a = a;
	a = b;
	Big_Data c(a);

}
