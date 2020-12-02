#ifndef H_CSVRow
#define H_CSVRow

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

class CSVRow {
   public:
//  std::string_view operator[](std::size_t index) const {
    std::string operator[](std::size_t index) const {
//      return std::string_view(&m_line[m_data[index] + 1], m_data[index + 1] - (m_data[index] + 1));
        return std::string(&m_line[m_data[index] + 1], m_data[index + 1] - (m_data[index] + 1));
    }
    std::size_t size() const {
        return m_data.size() - 1;
    }
    void readNextRow(std::istream& str) {
        std::getline(str, m_line);

        m_data.clear();
        m_data.emplace_back(-1);
        //m_data.__emplace_back(-1); 
        // for some reason everytime i switch computers intelisense is saying the emplace_back function is different.
        // I think its only a MacOS version function. Windows, ubuntu, and archLinux use emplace_back()
        std::string::size_type pos = 0;
        while ((pos = m_line.find(',', pos)) != std::string::npos) {
            m_data.emplace_back(pos);
            //m_data.__emplace_back(pos);
            ++pos;
        }
        // This checks for a trailing comma with no data after it.
        pos = m_line.size();
        m_data.emplace_back(pos);
        //m_data.__emplace_back(pos);
    }

   private:
    std::string m_line;
    std::vector<int> m_data;
};

std::istream& operator>>(std::istream& str, CSVRow& data) {
    data.readNextRow(str);
    return str;
}

#endif
