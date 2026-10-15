#include<iostream>
#include<string>
using namespace std;
class GameCharacter
{
public:
	string name;
	int hp;
	int level;
	// Constructor
	GameCharacter(string n, int h, int l)
	{
		name = n;// 將 n 存入 name
		hp = h;// 將 h 存入 hp
		level = l;// 將 l 存入 level
	}
	// 受到傷害
	void damage(int value)
	{
		hp -= value;// 1. hp 扣掉 value
		if (hp < 0)// 2. 如果 hp 小於 0 ，將 hp 設為 0
		{
			hp = 0;
		}
	}
	// 回復生命值
	void heal(int value)
	{
		hp += value;// 1. hp 加上 value
		if (hp > 100)// 2. 如果 hp 大於 100 ，將 hp 設為 100
		{
			hp = 100;
		}
	}
	// 升級
	void levelUp()
	{
		level += 1;// 1. level 加 1
		hp = 100;// 2. hp 回復成 100
	}
	// 顯示角色資料
	void show()
	{
		cout<<"Name:"<<name<<endl;// 顯示 name 、 hp 、 level
		cout << "Hp:" << hp << endl;
		cout << "Level:" << level << endl;
	}
};
class GameManager
{
private:
	GameCharacter player;// 要管理的角色

public:
	// Constructor：把名稱、血量、等級交給 player
	GameManager(string n, int h, int l) : player(n, h, l)
	{
	}

	// 選單迴圈
	void run()
	{
		int choice;
		do
		{
			cout << "\n========== 選單 ==========" << endl;
			cout << "1. 扣血" << endl;
			cout << "2. 回血" << endl;
			cout << "3. 升級" << endl;
			cout << "4. Show角色資料" << endl;
			cout << "0. 結束程式" << endl;
			cout << "請選擇：";
			cin >> choice;

			if (choice == 1)
			{
				int value;
				cout << "輸入傷害值：";
				cin >> value;
				player.damage(value);
				cout << endl;
				player.show();
			}
			else if (choice == 2)
			{
				int value;
				cout << "輸入回血量：";
				cin >> value;
				player.heal(value);
				cout << endl;
				player.show();
			}
			else if (choice == 3)
			{
				player.levelUp();
				cout << "角色升級成功！" << endl;
				player.show();
			}
			else if (choice == 4)
			{
				cout << endl;
				player.show();
			}
			else if (choice != 0)
			{
				cout << "無效的選項，請重新輸入。" << endl;
			}
		} while (choice != 0);
	}
};
int main()
{
	int a, c;
	string b;
	cout << "血量:";
	cin >> a;
	cout << "名稱:";
	cin >> b;
	cout << "等級:";
	cin >> c;
	GameManager game(b, a, c);// 名稱、血量、等級
	game.run();
	return 0;
}