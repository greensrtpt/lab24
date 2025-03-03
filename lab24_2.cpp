#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void printList(list<string> s){
	list<string>::iterator i;
	for( i = s.begin(); i != s.end(); i++){
		cout << *i << " ";
	}		
	cout << "\n";	
}

int main(){
	
	list<string> line_up;
	list<string>::iterator loc;
	
	line_up.push_back("Alice");
	line_up.push_back("Bob");
	
	loc = find(line_up.begin(),line_up.end(),"Bob");
	line_up.insert(loc,"Oscar");
	
	// Luffy, Sanji, Nami มาต่อแถวด้านหลัง
	line_up.push_back("Luffy");
	line_up.push_back("Sanji");
	line_up.push_back("Nami");
	
	// 2 คนแรก (Alice, Oscar) เข้าไปในสัมมนา (ออกจากแถว)
	line_up.pop_front();
	line_up.pop_front();
	
	// Naruto มาแทรกแถวหลัง Luffy
	loc = find(line_up.begin(), line_up.end(), "Luffy");
	if (loc != line_up.end()) {
	    ++loc;
	    line_up.insert(loc, "Narutu");
	}
	
	// Prayath ปวดท้องมาก เลยมาแทรกด้านหน้าแถวสุด
	line_up.push_front("Prayath");
	
	// Tony ยอมไม่ต่อแถว มาด้านหลัง Prayath
	loc = find(line_up.begin(), line_up.end(), "Prayath");
	if (loc != line_up.end()) {
	    ++loc;
	    line_up.insert(loc, "Tony");
	}
	
	// Bob ไม่ไหวแล้ว เปลี่ยนใจออกไป
	line_up.remove("Bob");
	
	// 3 คนที่เข้าไปสัมมนาแล้ว (Luffy, Prayath, Tony)
	line_up.remove("Luffy");
	line_up.remove("Prayath");
	line_up.remove("Tony");

	// แสดงผลลัพธ์ตามที่ต้องการ
	printList(line_up);
		
	return 0;
}