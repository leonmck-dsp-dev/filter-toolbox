# filter-toolbox

This library provides a set of easy-to-use classes for various audio filters, including low-pass, high-pass, DC (direct current), and peak notch filters, with more filter types on the way.

## Usage
Include the relevant header file for the filter you wish to use in your project.

The filters in this library are implemented as classes. To use a filter, you should first create an instance of the desired filter class.

You can then set the parameters of the filter using the setParameters function and filter audio data using the process function.

## Filters
### Low Pass Filter (LPF)
This is a filter that passes signals with a frequency lower than a certain cutoff frequency and attenuates frequencies higher than the cutoff frequency.

```c++
#include "lowPassFilter.h"

LowPassFilter lpf;
lpf.setParameters(centerFrequency);
float output = lpf.process(input);

```
### High Pass Filter (HPF)
This is a filter that passes signals with a frequency higher than a certain cutoff frequency and attenuates frequencies lower than the cutoff frequency.


```c++
#include "highPassFilter.h"

HighPassFilter hpf;
hpf.setParameters(centerFrequency);
float output = hpf.process(input);

```
### DC Filter
This is a filter that blocks the DC component (0 Hz) of a signal, allowing higher frequencies to pass.


```c++
#include "dcFilter.h"

DCFilter dcf;
dcf.setParameters(centerFrequency);
float output = dcf.process(input);

```
### Peak Notch Filter
This filter allows you to attenuate or boost frequencies around a center frequency. It's particularly useful for removing (notching out) or enhancing a narrow frequency band.

```c++
#include "peakNotchFilter.h"

PeakNotchFilter pnf;
pnf.setParameters(centerFrequency, Q, gain);
float output = pnf.process(input);

```

## Contributing
Contributions to expand this library are very welcome! We're looking forward to adding more filter types, as well as improving the existing filters.

Please fork the repository and submit a pull request with your changes.
please see  Contributing Guidelines
## License
This project is licensed under the MIT License.


