// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution 
{
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) 
    {
        return mergeSort(pairs, 0, pairs.size() - 1);
    }

private:
    vector<Pair> mergeSort(vector<Pair>& list, int start, int end)
    {
        if(end - start + 1 <= 1)
        {
            return list;
        }

        int mid = (start + end) / 2;
        mergeSort(list, start, mid);
        mergeSort(list, mid + 1, end);

        merge(list, start, mid, end);

        return list;
    }

    void merge(vector<Pair>& list, int start, int mid, int end)
    {
        vector<Pair> left(list.begin() + start, list.begin() + mid + 1);
        vector<Pair> right(list.begin() + mid + 1, list.begin() + end + 1);

        int i = 0; // index for left
        int j = 0; // index for right
        int k = start; // index for list

        while(i < left.size() && j < right.size())
        {
            if(left[i].key <= right[j].key)
            {
                list[k] = left[i];
                ++i;
            }
            else
            {
                list[k] = right[j];
                ++j;
            }
            ++k;
        }

        while(i < left.size())
        {
            list[k++] = left[i++];
        }

        while(j < right.size())
        {
            list[k++] = right[j++];
        }
    }

};
