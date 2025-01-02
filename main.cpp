#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution0 {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> B;
    std::vector<int> rez;
    for (int p = 0; p < nums.size(); p++) {
      B.push_back(nums[p]);
    }

    std::sort(begin(nums), end(nums));
    int i = 0, j = nums.size() - 1;
    while (i < j) {
      if (nums[i] + nums[j] == target) {
        for (int k = 0; k < nums.size(); k++) {
          if (B[k] == nums[i]) {
            rez.push_back(k);
          } else if (B[k] == nums[j]) {
            rez.push_back(k);
          }
        }
        return {rez[0], rez[1]};

      } else if (nums[i] + nums[j] > target) {
        j--;
      } else {
        i++;
      }
    }
    return {};
  }
};

class Solution1 {
 public:
  int longestConsecutive(std::vector<int>& nums) {
    std::sort(begin(nums), end(nums));
    if (nums.size() == 1) {
      return 1;
    }
    if (nums.size() == 0) {
      return 0;
    }
    int max_sequence = 0;
    int ths_sequence = 1;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1] - 1) {
        ths_sequence++;
      } else if (nums[i] == nums[i + 1]) {
        continue;
      } else {
        ths_sequence = 1;
      }
      max_sequence = std::max(max_sequence, ths_sequence);
    }
    max_sequence = std::max(max_sequence, ths_sequence);
    return max_sequence;
  }
};
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution2 {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* resultat = new ListNode(0);
    ListNode* resultat2 = resultat;

    int count = 0;
    int ostatoc = 0;
    bool flag1 = false;
    bool flag2 = false;
    do {
      if (l1 == nullptr) {
        flag1 = true;
        l1 = new ListNode(0);
        l1->next = new ListNode(0);
      }
      if (l2 == nullptr) {
        flag2 = true;
        l2 = new ListNode(0);
        l2->next = new ListNode(0);
      }

      count = l1->val + l2->val + ostatoc;

      if (count > 9) {
        ostatoc = count / 10;
        count = count % 10;
      } else {
        ostatoc = 0;
      }
      ListNode* newNode = new ListNode(count);

      resultat2->next = newNode;
      resultat2 = resultat2->next;
      if (flag1 && flag2) {
        return resultat->next;
      }

      l1 = l1->next;
      l2 = l2->next;
    } while ((l1 != nullptr || l2 != nullptr || ostatoc > 0));

    return resultat->next;
  }
};

// s = "abcabcbb"
// s = "dvdf"
class Solution3 {
 public:
  int lengthOfLongestSubstring(std::string s) {
    int n = s.length();
    int maxLength = 0;
    std::unordered_map<char, int> charMap;
    int left = 0;

    for (int right = 0; right < n; right++) {
      if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
        charMap[s[right]] = right;
        maxLength = std::max(maxLength, right - left + 1);
      } else {
        left = charMap[s[right]] + 1;
        charMap[s[right]] = right;
      }
    }

    return maxLength;
  }
};

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int l = 0, r = 0, p = 0;

    // if (m > n){
    //   return findMedianSortedArrays(nums2, nums1);
    // }

    for (int count = 0; count < ((n + m) / 2 + 1); count++) {
      if (l < (m - 1) && r < (n - 1)) {
        if (nums1[l] < nums2[r]) {
          l++;
          p = nums1[l];
        } else {
          r++;
          p = nums2[r];
        }
      } else if (l > m) {
        r++;
        p = nums2[r];
      } else if (r >= n) {
        l++;
        p = nums1[l];
      }
    }
    if ((m + n) % 2 == 1) {
      return p * 1.0;
    } else if (m < n) {
      return p * nums2[r];
    } else {
      return p * nums1[l];
    }
  }
};





// option + shift + A
int main() {
  int a[10]{};
  int (&b)[10] = a;
  b[0] = 1;
  std::cout << a[0] << '\n';
  return 0;
}
























































//                                  HARD

// class Solution {
//  public:
//   double findMedianSortedArrays(std::vector<int>& nums1,
//                                 std::vector<int>& nums2) {
//     int m = nums1.size();
//     int n = nums2.size();
//     int l = 0, r = 0, ml = 0, mr = 0;

//     for (int count = 0; count < (n + m) / 2; count++) {
//       if (l < m && r < n) {
//         if (nums1[l] < nums2[r]) {
//           l++;
//         } else {
//           r++;
//         }
//       } else if (l < n) {
//         l++;
//       } else {
//         r++;
//       }
//     }

//     if ((m + n) % 2 == 0) {
//       return (nums1[l] + nums2[r]) / 2.0;
//     } else {
//       return nums1[l];
//     }
//   }
// };

// class Solution {
//  public:
//   int lengthOfLongestSubstring(std::string s) {
//     std::unordered_map<char, int> umap;
//     int result = 0;

//     for (int i = 0; i < s.size(); i++)
//     {
//       if (umap.find(s[i]) == umap.end() && umap.find(s[i+1]) != umap.end()){
//         umap[s[i]] = i+1;
//         result = std::fmax(result, umap.size());
//         umap.clear();
//         i--;
//       }
//       else if (umap.find(s[i]) == umap.end()){
//         umap[s[i]] = i+1;
//         result = std::fmax(result, umap.size());
//       }
//       else{
//         umap.clear();
//         umap[s[i]] = i+1;
//         result = std::fmax(result, umap.size());
//       }
//     }

//     return result;
//   }
// };
// class Solution {
//  public:
//   int lengthOfLongestSubstring(std::string s) {
//     std::unordered_map<char, int> umap;
//     int k = 0, rez = 0;
//     char simb, t = ' ';
//     bool flag = false;

//     for (int i = 0; i < s.size(); i++) {
//       simb = s[i];
//       if (umap.find(simb) == umap.end()) {
//         k++;
//         umap.insert({simb, i + 1});
//         rez = std::max(rez, k);
//         if (umap.find(simb + 1) != umap.end() && !flag) {
//           t = s[i];
//         }

//         if (flag){
//           if (umap.find(t) != umap.end()){
//             k--;
//           }
//         }

//       } else {
//         umap.clear();
//         umap.insert({simb, i + 1});
//         k = 1;
//         if (umap.find(simb + 1) != umap.end() && !flag) {
//           t = s[i];
//         }
//         if (umap.find(t) == umap.end()) {
//           k++;
//           flag = true;
//         } else {
//           k--;
//         }

//         rez = std::max(rez, k);
//       }
//     }
//     return rez;
//   }
// };

// class Solution {
//  public:
//   int lengthOfLongestSubstring(std::string s) {
//     std::vector<std::string> vs;
//     for (int j = 0; j < s.size(); j++) {
//       for (int i = 0; i < s.size() - j; i++) {
//         bool flag = false;
//         std::string k = {s.begin() + j, s.end() - i};
//         for (int i1 = 0; i1 < k.size() - 1; i1++) {
//           for (int i2 = i1 + 1; i2 < k.size(); i2++) {
//             if (k[i1] == k[i2]) {
//               flag = true;
//             }
//           }
//         }
//         if (flag) {
//           continue;
//         }
//         std::cout << k << '\n';
//         vs.push_back(k);
//       }
//     }

//     std::cout << "//////////////////" << '\n';
//     int k = 0;
//     for (int i = 0; i < vs.size() - 1; i++) {
//       k = fmax(k, vs[i].length());
//     }
//     return k;
//   }
// };