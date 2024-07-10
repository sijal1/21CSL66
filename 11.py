#11.Write a program to contour an image
import cv2

# Read the image
image = cv2.imread('scenery.jpg') # Change this to the path of your image

# Convert the image to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply Gaussian blur to reduce noise
blurred = cv2.GaussianBlur(gray, (5, 5), 0)

# Find contours in the image
contours, _ = cv2.findContours(blurred, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Draw contours on a copy of the original image
contour_image = image.copy()
cv2.drawContours(contour_image, contours, -1, (0, 255, 0), 2)

# Display the original image with contours
cv2.imshow('Contoured Image', contour_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
