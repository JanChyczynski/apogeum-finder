# apogeum-finder
Library for finding the moment when a rocket has reached the highest point of its trajectory based on live altitude data. 
It filters the noise with moving average and the conditions are designed to avoid false-positives which could result e.g. in opening the rocket's parachute too early.\
Written in one day. 

## testing
We have also created data generator to test the algorithm against noisy input with outliers.

![image](https://user-images.githubusercontent.com/59477191/158926401-7f52aba7-f3c1-4ee3-a6c7-4e248a130af8.png)
