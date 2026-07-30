import { Router } from 'express';
import { getAllPackages } from '../controllers/packageController';

const router = Router();

router.get('/', getAllPackages);

export default router;
