#include <iostream>

// row ->  |--|--|--|
//         |--|--|--|
//         |--|--|--|
//         |--|--|--|

template <typename T = int>

class matrix
{
private:
  size_t mRows, mCols;
  std::vector<std::vector<T> *> rows;

public:
  matrix(const size_t &rows, const size_t &cols)
  {
    mRows = rows;
    mCols = cols;
    rows.reserve(mRows); // Reserve memory for matrix rows
    
    for (int i = 0; i < mRows; i++)
    {
      rows.push_back(new std::std::vector<T>(mCols));
    }
  }
};

int main(void)
{
  
  return(0);
}