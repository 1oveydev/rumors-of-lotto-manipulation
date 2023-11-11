import subprocess
import pandas as pd

data = pd.read_csv('LotteryData.csv')

win_dictionary = {i: 0 for i in range(1, 1092)}

for index, row in data.iterrows():
    command = [
        './simulation',
        str(row['drwtNo1']),
        str(row['drwtNo2']),
        str(row['drwtNo3']),
        str(row['drwtNo4']),
        str(row['drwtNo5']),
        str(row['drwtNo6']),
        str(row['total_paper']),
        str(row['drwNo'])
    ]
    
    result = subprocess.call(command)
    win_dictionary[row['drwNo']] = result

df = pd.DataFrame(win_dictionary.items(), columns=['drwNo', 'Win'])
df.to_csv('SimulationResult.csv', index=False)
