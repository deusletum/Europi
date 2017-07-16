// Copyright 2016 Richard R. Goodwin / Audio Morphology
//
// Author: Richard R. Goodwin (richard.goodwin@morphology.co.uk)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
// See http://creativecommons.org/licenses/MIT/ for more information.

/*
* Slew Profiles
* These are a series of Float arrays, which hold normalised values that 
* can be scaled to apply various Slew profiles to CV transitions.
* 
* These have been pre-calculated in order to save computational time
*/
static float slew_profiles[10][101]={
// Linear Rising - Offset 0
{0.0000,1.0000,2.0000,3.0000,4.0000,5.0000,6.0000,7.0000,8.0000,9.0000,10.0000,
11.0000,12.0000,13.0000,14.0000,15.0000,16.0000,17.0000,18.0000,19.0000,20.0000,
21.0000,22.0000,23.0000,24.0000,25.0000,26.0000,27.0000,28.0000,29.0000,30.0000,
31.0000,32.0000,33.0000,34.0000,35.0000,36.0000,37.0000,38.0000,39.0000,40.0000,
41.0000,42.0000,43.0000,44.0000,45.0000,46.0000,47.0000,48.0000,49.0000,50.0000,
51.0000,52.0000,53.0000,54.0000,55.0000,56.0000,57.0000,58.0000,59.0000,60.0000,
61.0000,62.0000,63.0000,64.0000,65.0000,66.0000,67.0000,68.0000,69.0000,70.0000,
71.0000,72.0000,73.0000,74.0000,75.0000,76.0000,77.0000,78.0000,79.0000,80.0000,
81.0000,82.0000,83.0000,84.0000,85.0000,86.0000,87.0000,88.0000,89.0000,90.0000,
91.0000,92.0000,93.0000,94.0000,95.0000,96.0000,97.0000,98.0000,99.0000,100.0000},

// Exponential Rising - Offset 1
{0.0000,4.8771,9.5163,13.9292,18.1269,22.1199,25.9182,29.5312,32.9680,36.2372,
39.3469,42.3050,45.1188,47.7954,50.3415,52.7633,55.0671,57.2585,59.3430,61.3259,
63.2121,65.0062,66.7129,68.3363,69.8806,71.3495,72.7468,74.0760,75.3403,76.5430,
77.6870,78.7752,79.8103,80.7950,81.7316,82.6226,83.4701,84.2763,85.0431,85.7726,
86.4665,87.1265,87.7544,88.3516,88.9197,89.4601,89.9741,90.4631,90.9282,91.3706,
91.7915,92.1918,92.5726,92.9349,93.2794,93.6072,93.9190,94.2156,94.4977,94.7660,
95.0213,95.2641,95.4951,95.7148,95.9238,96.1226,96.3117,96.4916,96.6627,96.8254,
96.9803,97.1275,97.2676,97.4009,97.5276,97.6482,97.7629,97.8720,97.9758,98.0745,
98.1684,98.2578,98.3427,98.4236,98.5004,98.5736,98.6431,98.7093,98.7723,98.8321,
98.8891,98.9433,98.9948,99.0438,99.0905,99.1348,99.1770,99.2172,99.2553,99.2917,
99.3262},

// Reverse Exponential Rising - Offset 2
{0.6738,0.7083,0.7447,0.7828,0.8230,0.8652,0.9095,0.9562,1.0052,1.0567,1.1109,
1.1679,1.2277,1.2907,1.3569,1.4264,1.4996,1.5764,1.6573,1.7422,1.8316,1.9255,
2.0242,2.1280,2.2371,2.3518,2.4724,2.5991,2.7324,2.8725,3.0197,3.1746,3.3373,
3.5084,3.6883,3.8774,4.0762,4.2852,4.5049,4.7359,4.9787,5.2340,5.5023,5.7844,
6.0810,6.3928,6.7206,7.0651,7.4274,7.8082,8.2085,8.6294,9.0718,9.5369,10.0259,
10.5399,11.0803,11.6484,12.2456,12.8735,13.5335,14.2274,14.9569,15.7237,16.5299,
17.3774,18.2684,19.2050,20.1897,21.2248,22.3130,23.4570,24.6597,25.9240,27.2532,
28.6505,30.1194,31.6637,33.2871,34.9938,36.7879,38.6741,40.6570,42.7415,44.9329,
47.2367,49.6585,52.2046,54.8812,57.6950,60.6531,63.7628,67.0320,70.4688,74.0818,
77.8801,81.8731,86.0708,90.4837,95.1229,100.0000},

// Logarithmic Rising - Offset 3
{0.0000,15.0515,23.8561,30.1030,34.9485,38.9076,42.2549,45.1545,47.7121,50.0000,
52.0696,53.9591,55.6972,57.3064,58.8046,60.2060,61.5224,62.7636,63.9377,65.0515,
66.1110,67.1211,68.0864,69.0106,69.8970,70.7487,71.5682,72.3579,73.1199,73.8561,
74.5681,75.2575,75.9257,76.5739,77.2034,77.8151,78.4101,78.9892,79.5532,80.1030,
80.6392,81.1625,81.6734,82.1726,82.6606,83.1379,83.6049,84.0621,84.5098,84.9485,
85.3785,85.8002,86.2138,86.6197,87.0181,87.4094,87.7937,88.1714,88.5426,88.9076,
89.2665,89.6196,89.9670,90.3090,90.6457,90.9772,91.3037,91.6254,91.9425,92.2549,
92.5629,92.8666,93.1661,93.4616,93.7531,94.0407,94.3245,94.6047,94.8814,95.1545,
95.4243,95.6907,95.9539,96.2140,96.4709,96.7249,96.9760,97.2241,97.4695,97.7121,
97.9521,98.1894,98.4241,98.6564,98.8862,99.1136,99.3386,99.5613,99.7818,100.0000},

// Reverse Logarithmic Rising - Offset 4
{0.0000,0.2156,0.4334,0.6534,0.8756,1.1001,1.3270,1.5563,1.7881,2.0223,
2.2591,2.4985,2.7406,2.9855,3.2331,3.4836,3.7370,3.9935,4.2530,4.5156,
4.7815,5.0507,5.3232,5.5992,5.8788,6.1621,6.4491,6.7399,7.0347,7.3336,
7.6367,7.9440,8.2558,8.5721,8.8931,9.2190,9.5498,9.8857,10.2269,10.5736,
10.9260,11.2841,11.6483,12.0187,12.3955,12.7791,13.1695,13.5671,13.9721,14.3848,
14.8056,15.2347,15.6724,16.1192,16.5754,17.0414,17.5176,18.0045,18.5027,19.0125,
19.5347,20.0697,20.6183,21.1811,21.7590,22.3526,22.9631,23.5911,24.2380,24.9048,
25.5927,26.3032,27.0377,27.7981,28.5861,29.4039,30.2537,31.1382,32.0604,33.0236,
34.0316,35.0888,36.2002,37.3717,38.6102,39.9238,41.3222,42.8172,44.4229,46.1573,
48.0426,50.1078,52.3907,54.9429,57.8362,61.1763,65.1268,69.9619,76.1954,84.9810,100.0000},

// Linear Falling - Offset 5
{100.0000,99.0000,98.0000,97.0000,96.0000,95.0000,94.0000,93.0000,92.0000,91.0000,
90.0000,89.0000,88.0000,87.0000,86.0000,85.0000,84.0000,83.0000,82.0000,81.0000,
80.0000,79.0000,78.0000,77.0000,76.0000,75.0000,74.0000,73.0000,72.0000,71.0000,
70.0000,69.0000,68.0000,67.0000,66.0000,65.0000,64.0000,63.0000,62.0000,61.0000,
60.0000,59.0000,58.0000,57.0000,56.0000,55.0000,54.0000,53.0000,52.0000,51.0000,
50.0000,49.0000,48.0000,47.0000,46.0000,45.0000,44.0000,43.0000,42.0000,41.0000,
40.0000,39.0000,38.0000,37.0000,36.0000,35.0000,34.0000,33.0000,32.0000,31.0000,
30.0000,29.0000,28.0000,27.0000,26.0000,25.0000,24.0000,23.0000,22.0000,21.0000,
20.0000,19.0000,18.0000,17.0000,16.0000,15.0000,14.0000,13.0000,12.0000,11.0000,
10.0000,9.0000,8.0000,7.0000,6.0000,5.0000,4.0000,3.0000,2.0000,1.0000,0.0000},

// Exponential Falling - Offset 6
{100.0000,95.1229,90.4837,86.0708,81.8731,77.8801,74.0818,70.4688,67.0320,63.7628,
60.6531,57.6950,54.8812,52.2046,49.6585,47.2367,44.9329,42.7415,40.6570,38.6741,
36.7879,34.9938,33.2871,31.6637,30.1194,28.6505,27.2532,25.9240,24.6597,23.4570,
22.3130,21.2248,20.1897,19.2050,18.2684,17.3774,16.5299,15.7237,14.9569,14.2274,
13.5335,12.8735,12.2456,11.6484,11.0803,10.5399,10.0259,9.5369,9.0718,8.6294,
8.2085,7.8082,7.4274,7.0651,6.7206,6.3928,6.0810,5.7844,5.5023,5.2340,4.9787,
4.7359,4.5049,4.2852,4.0762,3.8774,3.6883,3.5084,3.3373,3.1746,3.0197,2.8725,
2.7324,2.5991,2.4724,2.3518,2.2371,2.1280,2.0242,1.9255,1.8316,1.7422,1.6573,
1.5764,1.4996,1.4264,1.3569,1.2907,1.2277,1.1679,1.1109,1.0567,1.0052,0.9562,
0.9095,0.8652,0.8230,0.7828,0.7447,0.7083,0.6738},

// Reverse Exponential Falling - Offset 7
{99.3262,99.2917,99.2553,99.2172,99.1770,99.1348,99.0905,99.0438,98.9948,98.9433,
98.8891,98.8321,98.7723,98.7093,98.6431,98.5736,98.5004,98.4236,98.3427,98.2578,
98.1684,98.0745,97.9758,97.8720,97.7629,97.6482,97.5276,97.4009,97.2676,97.1275,
96.9803,96.8254,96.6627,96.4916,96.3117,96.1226,95.9238,95.7148,95.4951,95.2641,
95.0213,94.7660,94.4977,94.2156,93.9190,93.6072,93.2794,92.9349,92.5726,92.1918,
91.7915,91.3706,90.9282,90.4631,89.9741,89.4601,88.9197,88.3516,87.7544,87.1265,
86.4665,85.7726,85.0431,84.2763,83.4701,82.6226,81.7316,80.7950,79.8103,78.7752,
77.6870,76.5430,75.3403,74.0760,72.7468,71.3495,69.8806,68.3363,66.7129,65.0062,
63.2121,61.3259,59.3430,57.2585,55.0671,52.7633,50.3415,47.7954,45.1188,42.3050,
39.3469,36.2372,32.9680,29.5312,25.9182,22.1199,18.1269,13.9292,9.5163,4.8771,0.0000},

// Logarithmic Falling - Offset 8
{100.0000,84.9485,76.1439,69.8970,65.0515,61.0924,57.7451,54.8455,52.2879,50.0000,
47.9304,46.0409,44.3028,42.6936,41.1954,39.7940,38.4776,37.2364,36.0623,34.9485,
33.8890,32.8789,31.9136,30.9894,30.1030,29.2513,28.4318,27.6421,26.8801,26.1439,
25.4319,24.7425,24.0743,23.4261,22.7966,22.1849,21.5899,21.0108,20.4468,19.8970,
19.3608,18.8375,18.3266,17.8274,17.3394,16.8621,16.3951,15.9379,15.4902,15.0515,
14.6215,14.1998,13.7862,13.3803,12.9819,12.5906,12.2063,11.8286,11.4574,11.0924,
10.7335,10.3804,10.0330,9.6910,9.3543,9.0228,8.6963,8.3746,8.0575,7.7451,
7.4371,7.1334,6.8339,6.5384,6.2469,5.9593,5.6755,5.3953,5.1186,4.8455,
4.5757,4.3093,4.0461,3.7860,3.5291,3.2751,3.0240,2.7759,2.5305,2.2879,
2.0479,1.8106,1.5759,1.3436,1.1138,0.8864,0.6614,0.4387,0.2182,0.0000},

// Reverse Logarithmic Falling - Offset 9
{100.0000,99.7844,99.5666,99.3466,99.1244,98.8999,98.6730,98.4437,98.2119,97.9777,
97.7409,97.5015,97.2594,97.0145,96.7669,96.5164,96.2630,96.0065,95.7470,95.4844,
95.2185,94.9493,94.6768,94.4008,94.1212,93.8379,93.5509,93.2601,92.9653,92.6664,
92.3633,92.0560,91.7442,91.4279,91.1069,90.7810,90.4502,90.1143,89.7731,89.4264,
89.0740,88.7159,88.3517,87.9813,87.6045,87.2209,86.8305,86.4329,86.0279,85.6152,
85.1944,84.7653,84.3276,83.8808,83.4246,82.9586,82.4824,81.9955,81.4973,80.9875,
80.4653,79.9303,79.3817,78.8189,78.2410,77.6474,77.0369,76.4089,75.7620,75.0952,
74.4073,73.6968,72.9623,72.2019,71.4139,70.5961,69.7463,68.8618,67.9396,66.9764,
65.9684,64.9112,63.7998,62.6283,61.3898,60.0762,58.6778,57.1828,55.5771,53.8427,
51.9574,49.8922,47.6093,45.0571,42.1638,38.8237,34.8732,30.0381,23.8046,15.0190,0.0000},
};


static const char * slew_names[] = {
    "Linear Rising",
    "Exponential Rising",
    "Reverse Exponential Rising",
    "Logarithmic Rising",
    "Reverse Logarithmic Rising",
    "Linear Falling",
    "Exponential Falling",
    "Reverse Exponential Falling",
    "Logarithmic Falling",
    "Reverse Logarithmic Falling"
};
