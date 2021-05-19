# Purity

Purity is a color scheme that I am actively maintianing to fit my theming
tastes. One of the goals here is to support both light and dark themes, and to
be mostly defined with code to make updating the theme much easier.

The theme comes in 3 variations:

* Void: A dark theme with vibrant colors.
* Pastel: A dark theme with pastel-like colors.
* Mass: A light theme with ink-like colors.

# Supported Export Formats

* base16 (use a base16 builder)
* css
* plain text

## Building.

This color scheme is defined entirely with code and uses the HSLuv color space.

After installing a C compiler and a copy of GNU Make, run the following:

```
make
./purity
```

All of the files related to the color scheme will be output in ./dist
