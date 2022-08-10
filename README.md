# apogee-finder
Library for finding the moment when a rocket has reached the highest point of its trajectory based on live altitude data. 
It filters the noise with moving average and the conditions are designed to avoid false-positives which could result e.g. in opening the rocket's parachute too early.\
Because it was written on AGH Space Systems workshops we only had one day to write it. 

## testing
We have also created data generator to test the algorithm against noisy input with outliers.
![image](https://user-images.githubusercontent.com/59477191/184025482-d43c9bd4-98ec-4d27-85e8-d78901dc762a.png)
