#include <iostream>

class Dog{
  Dog();
  ~Dog();
 public:
  int energy;
  int mood;
  int need_toilet;
  void playing();
  void eating();
  void walking();
  void scold();
  void  castrate();
 private:
  void control();
  void control_die();
};

Dog::Dog(){
  energy = 100;
  mood = 100;
  need_toilet = 0;
}


void Dog::eating() {
  control();
  std::cout << "MMMMM... Yummy" << std::endl;
  energy = energy + 10;
  mood = mood - 5;
  need_toilet +=5;
}

void Dog::playing() {
  control();
  std::cout << "I'm having a lot of fun" << std::endl;
  energy = energy - 20;
  mood = mood + 40;
  need_toilet += 5;
}

void Dog::walking() {
  control();
  std::cout << "Let's go chasing cats" << std::endl;
  energy = energy - 30;
  mood = mood + 30;
  need_toilet += 5;
}

void Dog::castrate() {
  control();
  std::cout << "OOOO nooooo!!! Gospodin, don't do it" << std::endl;
  energy = energy - 50;
  mood = mood - 50;
  need_toilet += 5;
}

void Dog::scold() {
  control();
  std::cout << "But I just wanted to go to the toilet" << std::endl;
  energy = energy - 10;
  mood = mood - 40;
  need_toilet += 5;
}

void Dog::control() {
  if(energy <= 10){
    std::cout << "I need sleep" << std::endl;
    eating();
  }
  else if(mood <= 10) {
    std::cout << "please, play with me" << std::endl;
    playing();
  }
  else if(need_toilet >= 20){
    std::cout << "I need toilet" << std::endl;
    walking();
  }
}

void Dog::control_die() {
  if (energy < 0 || mood < 0)
    std::cout << "good bye my friend... I'm going to the stars" << std::endl;
}


int main() {
  int n;   //количество действий с каждым животным;
  int N;    //количество экземпляров животного СОБАКА;
  std::cin >> n;
  std::cin >> N;
  Dog* pets = new Dog[N];
  for (int j = 0; j < n; j ++) {
    for (int i = 0; i < N; i++) {
      Dog[i] = rand(Dog::playing(), Dog::eating(), Dog::walking(), Dog::scold(), Dog::castrate());
    }
  }
  delete[] pets;
  return 0;
}
