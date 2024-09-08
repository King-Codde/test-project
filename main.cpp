#include <vector>
#include <iostream>

template <typename T>
std::vector<T> SMA(std::vector<T>& p, int window){
    std::vector<T> new_p;
    T sum = 0;

    if (window == 0 || p.size() < window){
        new_p = p;
        return p;
    }

    for (int i = window-1; i >=0; i--){
        sum+=p[i];
    }


    sum = sum/window;
    new_p.push_back(sum);

    for(int i = window; i < p.size(); i++){
        sum+= (p[i] - p[i-window])/window;
        new_p.push_back(sum);
    }

    return new_p;
}

template <typename T>
void test(std::vector<T>& data,std::vector<T>& correct_data, int window){
    std::vector<float> new_data = SMA(data, window);

    if (new_data == correct_data){
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
}



int main(){
    std::vector<float> data = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::vector<float> correct_data = {2.0, 3.0, 4.0};
    size_t window = 3;
    test(data, correct_data, window);

    correct_data = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    window = -1;
    test(data, correct_data, window);

    correct_data = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    window = 10;
    test(data, correct_data, window);

    correct_data = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    window = 2;
    test(data, correct_data, window);
}