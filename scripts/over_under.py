#Created by Kurt Wimer
#outputs number of values over and under the hard-coded split 

import csv
def main():
    over = under =0
    split = 8717713408
    with open('trace.csv','r') as f:
        count = 0
        reader = csv.reader(f);
        for row in reader:
            count = count+1
            if (count >100000):
                break
            if int(row[4])<=split:
                under = under+1
            else:
                over = over+1
    print("over:" + str(over))
    print("under:" + str(under))
main()
