// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
 int p = 0;
 for (int i = 0; i < len - 1; i++) {
  for (int j = i + 1; j < len; j++) {
   if (arr[i] + arr[j] == value) {
      p++;
   }
  }
 }
return p;
}

int countPairs2(int *arr, int len, int value) {
 int count = 0;
 int l = 0, r = len - 1;
 while (l < r - 1) {
  int m = (r + l) / 2;
  if (arr[m] <= value)
     l = m + 1;
  else
     r = m;
 }
 len = r;
 for (int i = 0; i < len; i++) {
  for (int j = len; j > i; j--) {
   if (arr[i] + arr[j] > value) continue;
   if (arr[i] + arr[j] < value) break;
   if (arr[i] + arr[j] == value) {
      count++;
   }
  }
 }
 return count;
}

int countPairs3(int *arr, int len, int value) {
 int p = 0, l = 0, r = len - 1;
 while (l < r - 1) {
  int mid = (l + r) / 2;
  if (arr[mid] <= value)
   l = mid;
  else
   r = mid;
 }
 len = r - 1;
  for (int i = 0; i <len; i++) {
   l = i+1, r = len-1;
   int p2 = 0;
   while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] < (value - arr[i]))
     l = mid + 1;
    else
      r = mid;
   }
   while (arr[l] == (value - arr[i])) {
    p2++;
    l++;
   }
    p += p2;
  }
  return p;
}
