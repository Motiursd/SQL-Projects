import { Request, Response } from 'express';
import prisma from '../config/db';

export const getAllPackages = async (req: Request, res: Response) => {
  try {
    const packages = await prisma.tourPackage.findMany();
    res.status(200).json({
      success: true,
      message: 'Packages retrieved successfully',
      data: packages,
    });
  } catch (error) {
    res.status(500).json({
      success: false,
      message: 'Failed to fetch packages',
      error: error,
    });
  }
};
