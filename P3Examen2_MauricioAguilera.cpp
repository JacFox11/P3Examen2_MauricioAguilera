#include "Stack.cpp"

int main(){
	char response='s';
	while (response=='s'){
		string value;
		cout<<"Input the arithmetic sequnce to resolve: ";
		cin>>value;
		Stack* pila=new Stack();
		int counter=0;
		string temp;
		for (int i=0; i<value.size(); i++){
			temp="";
			while (value[i]!='+' && value[i]!='-' && value[i]!='*' && value[i]!='/' && i<value.size()){
				temp+=value[i];
				i++;
			}
			if (temp!=""){
				pila->Push(temp);
				temp="";
				counter++;
			}
			if (value[i]=='-'){
				pila->Push("+");
				counter++;
				temp+=value[i];
				i++;
				while (value[i]!='+' && value[i]!='-' && value[i]!='*' && value[i]!='/' && i<value.size()){
					temp+=value[i];
					i++;
				}
			}
			if (temp!=""){
				pila->Push(temp);
				temp="";
				counter++;
			}
			if (value[i]=='+' || value[i]=='*' || value[i]=='/'){
				temp+=value[i];
			}
			if (temp!=""){
				pila->Push(temp);
				temp="";
				counter++;
			}
		}
		int cont=0;
		int counter_temp=counter;
		int result;
		ofstream Escribir;
        Escribir.open("Log.txt", ios::app);
        Escribir<<"New Operation"<<endl;
		while (cont<counter){//se repetira 
			int cont2=0;
			Node* node_temp=pila->Top();
			while (cont2<counter_temp){
				node_temp->print();
				Escribir<<node_temp->getValue();
				node_temp=node_temp->getNext();
				cont2++;
			}
			cout<<endl;
			Escribir<<endl;
			int number1= atoi(pila->Pop()->getValue().c_str());
			string operador=pila->Pop()->getValue();
			int number2=atoi(pila->Pop()->getValue().c_str());
			if (operador=="+"){
				result=number1+number2;
				stringstream ss;
				ss << result;
				string temp_resultado = ss.str();
				pila->Push(temp_resultado);
			}else{
				if (operador=="*"){
					result=number1*number2;
					stringstream ss;
					ss << result;
					string temp_resultado = ss.str();
					pila->Push(temp_resultado);
				}else{
					if (operador=="/"){
						result=number2/number1;
						stringstream ss;
						ss << result;
						string temp_resultado = ss.str();
						pila->Push(temp_resultado);
					}
				}
			}
			cont+=3;
			counter_temp-=2;
		}
		pila->Top()->print();
		Escribir<<pila->Top()->getValue();
		cout<<endl;
		Escribir<<endl<<endl;
		Escribir.close();
		pila->~Stack();
	}
	
	system("pause");
	return 0;
}
