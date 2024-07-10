#8.Write a program to show rotation, scaling, and translation on an image

import cv2
import numpy as np

# Read the image
image = cv2.imread('delvin.jpg') # Change this to the path of your image

# Define rotation angle (in degrees), scaling factor, and translation distances
angle = 45
scale_factor = 0.5
tx = 100
ty = 50

# Get image height and width
height, width = image.shape[:2]

# Define rotation matrix
rotation_matrix = cv2.getRotationMatrix2D((width / 2, height / 2), angle, scale_factor)

# Apply rotation to the image
rotated_image = cv2.warpAffine(image, rotation_matrix, (width, height))

# Define translation matrix
translation_matrix = np.float32([[1, 0, tx], [0, 1, ty]])

# Apply translation to the image
translated_image = cv2.warpAffine(image, translation_matrix, (width, height))

# Display the original image, rotated image, and translated image
cv2.imshow('Original Image', image)
cv2.imshow('Rotated Image', rotated_image)
cv2.imshow('Translated Image', translated_image)

cv2.waitKey(0)
cv2.destroyAllWindows()


