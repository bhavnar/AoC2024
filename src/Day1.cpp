#include "../include/Day1.hpp"

void Day1::parseInput(const std::string& file_name) {
    
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "File for day 1 cannot be opened!" << std::endl;
        return;
    }
    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        if (line.empty()) {
            std::cerr << "Empty line received " << count << std::endl;
            continue;
        }
        if (!isLineValid(line)) {
            std::cerr << "Invalid line received " << count << std::endl;
            continue;
        }
        std::stringstream s(line);
        int l, r;
        s >> l >> r;
        m_left.push_back(l);
        m_right.push_back(r);
    }
    
    std::sort(m_left.begin(), m_left.end());
    std::sort(m_right.begin(), m_right.end());
    
    file.close();
}

bool Day1::isLineValid(const std::string& line) {
    std::stringstream s(line);
    int l , r;
    if (!(s >> l >> r)) {
        return false;
    }
    s >> l >> r;
    //check if third element exists in the list
    std::string next;
    if (s >> next) {
        return false;
    }
    return true;
}

int Day1::totalDistance() {
    int d = 0;
    if (m_left.size() == m_right.size()) {
        for (int i=0; i< m_left.size(); i++) {
            d += std::abs(m_right[i] - m_left[i]);
        }
    }
    return d;
}

int Day1::calcSimilarity() {
    int score = 0;
    std::map<int, int> map_freq;
    
    for (int num: m_right) {
        map_freq[num]++;
    }
    for (int num: m_left) {
        score += num * map_freq[num];
    }
    return score;
}

void Day1::ComputeDay(const int& part) {
    std::cout << "Calculating total distance... ";
    parseInput("../resource/day1.txt");
    int distance = totalDistance();
   
    if (part == 1) {
        std::cout << "The computed distance is " << distance << std::endl;
        return;
    }
    
    int similarity = calcSimilarity();
   
    std::cout << "Similarity score is " << similarity << std::endl;
}

