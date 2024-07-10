#10.Write a program to blur and smoothing an image.

import cv2

# Read the image
image = cv2.imread('scenery.jpg') # Change this to the path of your image

# Apply Gaussian blur to the image
blurred = cv2.GaussianBlur(image, (15, 15), 0)

# Apply bilateral filter for smoothing
smoothed = cv2.bilateralFilter(image, 5, 50, 50)

# Display the original image, blurred image, and smoothed image
cv2.imshow('Original Image', image)
cv2.imshow('Blurred Image', blurred)
cv2.imshow('Smoothed Image', smoothed)
cv2.waitKey(0)
cv2.destroyAllWindows()
