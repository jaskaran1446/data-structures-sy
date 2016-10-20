#include<iostream>
#include<math.h>

class term{
    int coe;
    int exp;
    term* next;
    public:    
        term(int c=0,int e=0){
            coe = c;
            exp =e;
            next = NULL;
        }
        friend class polynomial;
};

class polynomial{
    public:
        term* first;
        polynomial(){
            first = NULL;
        }
        void create();
        polynomial add(polynomial p){
        	term* a = first;
    		term* b = p.first;
    		polynomial c;
   		    while(a && b){	
		        if(a->exp == b->exp){
        		    term* newterm = new term(a->coe+b->coe,a->exp);
            		c.append(newterm);
            		a = a->next;
            		b = b->next;
        		}
        		else if(a->exp > b->exp){
            		c.append(a);
            		a = a->next;
        		}
        		else{
            		c.append(b);
            		b = b->next;
        		}
    		}
    		term* rem;
    		if(a!=NULL)
    			rem = a;
    		else
    			rem = b;
    		while(rem!=NULL){
        		c.append(rem);
        		rem = rem->next;
    		}
    		return c;
        
        }
        polynomial subtract(polynomial p){
        	term* a = first;
    		term* b = p.first;
    		polynomial c;
   		    while(a && b){
   		    	
		        if(a->exp == b->exp){
        		    term* newterm = new term(a->coe-b->coe,a->exp);
            		c.append(newterm);
            		a = a->next;
            		b = b->next;
        		}
        		else if(a->exp > b->exp){
            		c.append(a);
            		a = a->next;
        		}
        		else{
            		c.append(b);
            		b = b->next;
        		}
    		}
    		while(a){
        		c.append(a);
        		a = a->next;
    		}
    		while(b){
        		c.append(b);
        		b = b->next;
    		}
    		return c;
        }
        polynomial multiply(polynomial p){
        	term* a = first;
    		term* b;
    		polynomial res;
			while(a){
        		b = p.first;
        		polynomial tem;
        		while(b){
            		term* newterm = new term(a->coe*b->coe,a->exp+b->exp);
            		tem.append(newterm);
            		b = b->next;
        		}
           		res = res.add(tem);
				a = a->next;
    		}
    		return res;
		}
        void display();
        void evaluate(int);
    private:
        void append(term*);
};
void polynomial::create(){
    std::cout<<"Enter no. of terms:\t";
    int n;
    std::cin>>n;
    while(n--){
        int c,e;
        std::cout<<"Enter co-efficient and exponent\n";
        std::cin>>c>>e;
        term* newterm = new term(c,e);
         append(newterm);
    }
}
void polynomial::append(term* t){
	t->next = NULL;
    if(first == NULL){
        first = t;
        return;
    }
    term* tem = first;
    while (tem->next){
        tem = tem->next;
    }
    tem->next = t;
}
void polynomial::display(){
    if(first == NULL){
        std::cout<<"NO TERMS\n";
        return;
    }
    term* t = first;
    std::cout<<t->coe<<"*x^"<<t->exp;
    t=t->next;
    while(t){
        std::cout<<"+"<<t->coe<<"*x^"<<t->exp;
        t = t->next;
    }
    std::cout<<"\n";
}

void polynomial::evaluate(int x){
	if(first == NULL){
        std::cout<<"NO TERMS\n";
        return;
    }
    term* t = first;
    int val = 0;
    while(t){
        val += t->coe * int(pow(x,t->exp));
        t = t->next;
    }
    display();
    std::cout<<"Evaluated to "<<val<<"\n";
}	

int main(){
    polynomial p1,p2,s,d,p;
    int ch,x;
    std::cout<<"1st polynomial\n";
    p1.create();
    p1.display();
    std::cout<<"2nd polynomial\n";
    p2.create();
    p2.display();
    std::cout<<"Enter 1 to add, 2 to subtract, 3 to multiply, 4 to evaluate \n";
    std::cin>>ch;
    switch(ch){
        case 1:
            s = p1.add(p2);
            std::cout<<"Sum\n";
            s.display();
            break;
        case 2:
            d = p1.subtract(p2);
            std::cout<<"Difference\n";
            d.display();
            break;
        case 3:
            p = p1.multiply(p2);
            std::cout<<"Product\n";
            p.display();
            break;
        case 4:
			std::cout<<"Enter value of x\t";
			std::cin>>x;
			p1.evaluate(x);
			p2.evaluate(x);
			break;
        default:
            std::cout<<"Invalid input";
        }
    return 0;
}
