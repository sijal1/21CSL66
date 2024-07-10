#9.Read an image and extract and display low-level features such as edges, textures using filtering techniques.

import cv2
import numpy as np

# Read the image
image = cv2.imread('scenery.jpg') # Change this to the path of your image

# Convert the image to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply Gaussian blur to reduce noise
blurred = cv2.GaussianBlur(gray, (5, 5), 0)

# Apply Laplacian filter for edge detection
laplacian = cv2.Laplacian(blurred, cv2.CV_64F)

# Apply Sobel filters for edge detection in both X and Y directions
sobel_x = cv2.Sobel(blurred, cv2.CV_64F, 1, 0, ksize=5)
sobel_y = cv2.Sobel(blurred, cv2.CV_64F, 0, 1, ksize=5)

# Display the original image and the extracted features
cv2.imshow('Original Image', image)
cv2.imshow('Blurred Image', blurred)
cv2.imshow('Laplacian Filter', laplacian)
cv2.imshow('Sobel X Filter', sobel_x)
cv2.imshow('Sobel Y Filter', sobel_y)

cv2.waitKey(0)
cv2.destroyAllWindows()
 
